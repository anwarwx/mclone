#include "../include/event.h"

void Event::keyCB(GLFWwindow* w, int k, int sc, int a, int m) {
  for (auto const& [v, f] : gEvent()->gFun()) {
    if (v == k && a == GLFW_PRESS) f(w); return;
  }
}

void Event::cursorCB(GLFWwindow* w, double x, double y) {
  Vec3((float) x, (float) y).pVec();
}

void Event::resizeCB(GLFWwindow* w, int vw, int vh) {
  glViewport(0, 0, vw, vh);
}

void Event::CB(GLFWwindow* w) {
  glfwSetKeyCallback(w, keyCB);
  glfwSetCursorPosCallback(w, cursorCB);
  glfwSetFramebufferSizeCallback(w, resizeCB);
}
