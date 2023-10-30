#include "../include/window.h"
#include "../include/event.h"

#define inp Event::gEvent()

int main() {
  Window glfwWindow;
  if (!glfwWindow.cWin()) return 1;
  
  while (!glfwWindowShouldClose(glfwWindow.gWin())) {
    glClear(GL_COLOR_BUFFER_BIT);

    inp->CB(glfwWindow.gWin());

    glfwSwapBuffers(glfwWindow.gWin());
    glfwPollEvents();
  }
  glfwTerminate();

  std::cout << "-- END --\n";
  return 0;
}
