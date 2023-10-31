#include "../include/event.h"
#include "../include/shader.h"

#define inp Event::gEvent()

int main() {
  Window glfwWindow;
  if (!glfwWindow.cWin()) return 1;

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "[!] gladLoadGLLoader()" << std::endl;
    return 1;
  }

  Shader shdr;
  shdr.run();

  glViewport(0, 0, glfwWindow.gWidth(), glfwWindow.gHeight());
  while (!glfwWindowShouldClose(glfwWindow.gWin())) {
    inp->CB(glfwWindow.gWin());
    
    glClearColor(0.1, 0.2, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    shdr.draw();

    glfwSwapBuffers(glfwWindow.gWin());
    glfwPollEvents();
  }
  shdr.free();
  glfwTerminate();

  std::cout << "-- END --\n";
  return 0;
}
