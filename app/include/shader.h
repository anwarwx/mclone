#ifndef SHADER_H_
#define SHADER_H_

#include <iostream>
#include <vector>

const char *vsrc = R"(
  #version 330 core
  layout (location = 0) in vec3 aPos;
  
  void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
  }
)";

const char *fsrc = R"(
  #version 330 core
  out vec4 FragColor;
  
  void main() {
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
  }
)";

#define V_SIZE 6

struct Vertex {
  Vec3 pos;
};

struct Shape {
  Vertex v[V_SIZE];
  unsigned int VAO;
  unsigned int VBO;
};

class Shader {
  private:
    std::vector<unsigned int> ss;
    unsigned int p;
    int success;
    char info[512];

    Shape s = {
      {
        {Vec3(-0.5, -0.5)}, {Vec3(0.5, -0.5)}, {Vec3(0.0, 0.5)},
        {s.v[0].pos+Vec3(0.5, 1.0)}, {s.v[1].pos+Vec3(0.5, 1.0)}, {s.v[2].pos+Vec3(0.5, -1.0)}
      }
    };

  public:
    Shader() {}
    ~Shader() {}

    unsigned int gProgram(void) { return p; }
    unsigned int gVAO(void) { return s.VAO; }
    unsigned int gVBO(void) { return s.VBO; }

    void add(unsigned int s) { ss.push_back(s); }

    void run(void) {
      unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
      if (compile(vs, vsrc, "GL_VERTEX_SHADER")) return;
      add(vs);
      
      unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
      if (compile(fs, fsrc, "GL_FRAGMENT_SHADER")) return;
      add(fs);

      if (link()) return;
      setup();
    }

    int compile(unsigned int s, const char* src, const std::string& n) {
      glShaderSource(s, 1, &src, NULL);
      glCompileShader(s);

      glGetShaderiv(s, GL_COMPILE_STATUS, &success);
      if (!success) {
        glGetShaderInfoLog(s, 512, NULL, info);
        std::cout << "[!] " << n << info << '\n';
        return 1;
      }
      return 0;
    }

    int link(void) {
      p = glCreateProgram();
      for (auto& s : ss) glAttachShader(p, s);
      glLinkProgram(p);

      glGetProgramiv(p, GL_LINK_STATUS, &success);

      if (!success) {
        glGetProgramInfoLog(p, 512, NULL, info);
        std::cout << "[!] glLinkProgram()" << ": " << info << '\n';
        return 1;
      }
      for (auto& s : ss) glDeleteShader(s);
      return 0;
    }

    void setup(void) {
      glGenVertexArrays(1, &s.VAO);
      glad_glBindVertexArray(s.VAO);

      glGenBuffers(1, &s.VBO);
      glBindBuffer(GL_ARRAY_BUFFER, s.VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*V_SIZE, s.v, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
      glEnableVertexAttribArray(0);

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);
    }

    void draw(void) {
      glUseProgram(p);
      glBindVertexArray(s.VAO);
      glDrawArrays(GL_TRIANGLES, 0, V_SIZE);
    }

    void free(void) {
      glDeleteVertexArrays(1, &s.VAO);
      glDeleteBuffers(1, &s.VBO);
      glDeleteProgram(p);
    }
};

#endif // SHADER_H_
