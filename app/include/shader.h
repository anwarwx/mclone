#ifndef SHADER_H_
#define SHADER_H_

#include <iostream>
#include <vector>

#include "glad.h"
#include "vec.h"

#define V_SIZE 6

extern const char *vsrc;
extern const char *fsrc;

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
        
        {s.v[0].pos+Vec3(0.5, 1.0)},
        {s.v[1].pos+Vec3(0.5, 1.0)},
        {s.v[2].pos+Vec3(0.5, -1.0)}
      }
    };

  public:
    Shader() {}
    ~Shader() {}

    unsigned int gProgram(void) { return p; }
    unsigned int gVAO(void) { return s.VAO; }
    unsigned int gVBO(void) { return s.VBO; }

    void add(unsigned int s) { ss.push_back(s); }
    void run(void);
    int compile(unsigned int s, const char* src, const std::string& n);
    int link(void);
    void setup(void);
    void draw(void);
    void free(void);
};

#endif // SHADER_H_
