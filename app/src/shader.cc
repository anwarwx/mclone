#include "../include/shader.h"

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

void Shader::run(void) {
  unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
  if (compile(vs, vsrc, "GL_VERTEX_SHADER")) return;
  add(vs);
  
  unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
  if (compile(fs, fsrc, "GL_FRAGMENT_SHADER")) return;
  add(fs);
  
  if (link()) return;
  setup();
}

int Shader::compile(unsigned int s, const char* src, const std::string& n) {
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

int Shader::link(void) {
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

void Shader::setup(void) {
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

void Shader::draw(void) {
  glUseProgram(p);
  glBindVertexArray(s.VAO);
  glDrawArrays(GL_TRIANGLES, 0, V_SIZE);
}

void Shader::free(void) {
  glDeleteVertexArrays(1, &s.VAO);
  glDeleteBuffers(1, &s.VBO);
  glDeleteProgram(p);
}
