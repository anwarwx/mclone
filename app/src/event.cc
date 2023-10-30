#include "../include/event.h"

void Event::keyCB(GLFWwindow* w, int k, int sc, int a, int m) {
  for (auto const& [b, f] : gEvent()->fs) {
    if (b == k && a == GLFW_PRESS) {
      std::cout << "PRESSED : " << (char) b << '\n';
      f(w); return;
    }
  }
}

void Event::cursorCB(GLFWwindow* w, double x, double y) {
  Vec3((float) x, (float) y).pVec();
}

void Event::CB(GLFWwindow* w) {
  glfwSetKeyCallback(w, keyCB);
  glfwSetCursorPosCallback(w, cursorCB); 
}
