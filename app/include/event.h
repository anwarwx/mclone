#ifndef EVENT_H_
#define EVENT_H_

#include "window.h"
#include <map>
#include "vec.h"

class Event {
  std::map<int, std::function<void(GLFWwindow*)>> fs = {
    {
      GLFW_KEY_E,
      [](GLFWwindow* w) {
        glfwSetWindowShouldClose(w, GL_TRUE);
      }
    }
  };

  public:
    Event(Event const&) = delete;
    Event& operator=(Event const&) = delete;
    
    ~Event() {}
    static Event* gEvent() { static Event e; return &e; }
    static void keyCB(GLFWwindow* w, int k, int sc, int a, int m);
    static void cursorCB(GLFWwindow* w, double x, double y);
    
    void CB(GLFWwindow* w);
  
  private:
    explicit Event() {}
};

#endif // EVENT_H_
