#include "../include/window.h"

Window::Window() : w(1280), h(720), t("mclone") {}
Window::Window(int w_, int h_, const char* t_) : w(w_), h(h_), t(t_) {}

bool Window::cWin(void) {
  if (!glfwInit()) {
    std::cout << "[!] glfwInit()\n";
    return false;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  win = glfwCreateWindow(w, h, t, NULL, NULL);
  if (!win) {
    std::cout << "[!] glfwCreateWindow()\n";
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(win);
  return true;
}
