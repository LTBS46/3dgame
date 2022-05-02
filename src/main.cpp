#include "config.hpp"
#include "HandleWindow.hpp"
#include "FrameWork.hpp"

extern "C" {
#include "glad/gl.h"
#include "GLFW/glfw3.h"
}

using std::string;

int main() {
    string title = "A window";
    HandleWindow* win = Framework::get_instance().new_window(800, 800, title, WindowFlags::Decorated | WindowFlags::Focused | WindowFlags::Resizable | WindowFlags::Visible);
    while (!*win) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win->operator GLFWwindow * ());
        glfwPollEvents();
    }
    delete win;
    glfwTerminate();
    return VERSION_MAJOR;
}