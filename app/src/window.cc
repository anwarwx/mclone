#include "../include/window.h"

Window::Window() : w(1280), h(720), t("mclone") {}
Window::Window(int w_, int h_, const char* t_) : w(w_), h(h_), t(t_) {}

bool Window::cWin(void) {
  if (!glfwInit()) {
    std::cout << "error: glfwInit()\n";
    return false;
  }

  win = glfwCreateWindow(w, h, t, NULL, NULL);
  if (!win) {
    std::cout << "error: glfwCreateWindow()\n";
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(win);
  return true;
}
