#ifndef EVENT_H_
#define EVENT_H_

#include "window.h"
#include "vec.h"
#include <map>

class Event {
  public:
    Event(Event const&) = delete;
    Event& operator=(Event const&) = delete;
    
    ~Event() {}
    static Event* gEvent() { static Event e; return &e; }
    static void keyCB(GLFWwindow* w, int k, int sc, int a, int m);
    static void cursorCB(GLFWwindow* w, double x, double y);
    static void resizeCB(GLFWwindow* w, int vw, int vh);

    void CB(GLFWwindow* w);
    std::map<int, std::function<void(GLFWwindow*)>>& gFun(void) { return f; }
    void pEvent(const std::string& e, const std::string& o) { std::cout << e << " : " << o << '\n'; }
  
  private:
    explicit Event() {}
    std::map<int, std::function<void(GLFWwindow*)>> f = {
    {
      GLFW_KEY_ESCAPE,
      [this](GLFWwindow* w) { pEvent("PRESSED", "ESC"); glfwSetWindowShouldClose(w, GL_TRUE); }
    }
  };
};

#endif // EVENT_H_
