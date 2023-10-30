#ifndef WINDOW_H_
#define WINDOW_H_

#include <iostream>
#include "glfw3.h"

class Window {
  int w;
  int h;
  const char* t;
  GLFWwindow* win = nullptr;

  public:
    Window();
    Window(int w_, int h_, const char* t_);
    ~Window() { glfwDestroyWindow(win); }

    int gWidth(void) { return w; }
    int gHeight(void) { return h; }
    std::string gTitle(void) const { return t; }
    GLFWwindow* gWin(void) { return win; }

    void sWidth(int w_) { w = w_; }
    void sHeight(int h_) { h = h_; }

    bool cWin(void);
};

#endif // WINDOW_H_
