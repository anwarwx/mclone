#include "../include/event.h"
#include "../include/shader.h"

#define inp Event::gEvent()

int main() {
  Window glfwWindow;
  if (!glfwWindow.cWin()) return 1;

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "[!] ERROR GLAD" << std::endl;
    return 1;
  }

  Shader shader; shader.run();

  glViewport(0, 0, glfwWindow.gWidth(), glfwWindow.gHeight());
  while (!glfwWindowShouldClose(glfwWindow.gWin())) {
    inp->CB(glfwWindow.gWin());
    
    glClearColor(0.1, 0.2, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shader.gProgram());
    glBindVertexArray(shader.gVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(glfwWindow.gWin());
    glfwPollEvents();
  }
  shader.free();
  glfwTerminate();

  std::cout << "-- END --\n";
  return 0;
}
