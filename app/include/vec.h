#ifndef VEC3_H_
#define VEC3_H_

#include <iostream>
#include <cmath>
#include <iomanip>

class Vec3 {
  public:
    float x = 0.0, y = 0.0, z = 0.0;

    Vec3() {}
    Vec3(float x_ = 0.0, float y_ = 0.0, float z_ = 0.0) : x(x_), y(y_), z(z_) {}
    ~Vec3() {}
    Vec3 operator+(const Vec3& v) { return Vec3(x+v.x, y+v.y, z+v.z); }
    Vec3 operator-(const Vec3& v) { return Vec3(x-v.x, y-v.y, z-v.z); }
    Vec3 operator*(const int m) { return Vec3(x*m, y*m, z*m); }
    Vec3 operator/(const int m) { return Vec3(x/m, y/m, z/m); }
    float operator[](const int i) {
      if (i==0) return x;
      if (i==1) return y;
      if (i==2) return z;
      return 0.0;
    }
    float dist(const Vec3& v) { return sqrt(pow(v.x-x, 2) + pow(v.y-y, 2) + pow(v.z-z, 2)); }
    void pVec(void) { std::cout.precision(3); std::cout << std::fixed << '[' << x << ", " << y << ", " << z << "]\n"; }
};

#endif // VEC3_H_

#ifndef VEC4_H_
#define VEC4_H_

class Vec4 {
  public:
    float r = 0.0, g = 0.0, b = 0.0, a = 1.0;

    Vec4() {}
    Vec4(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
    ~Vec4() {}
    float operator[](const int i) {
      if (i==0) return r;
      if (i==1) return g;
      if (i==2) return b;
      if (i==3) return a;
      return 0.0;
    }
    void pVec(void) { std::cout << '[' << r << ", " << g << ", " << b << ", " << a << "]\n"; }
};

#endif // VEC4_H_
