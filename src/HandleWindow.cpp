#include "HandleWindow.hpp"
#include <cstring>
extern "C" {
#include <glad/gl.h>
#include <GLFW/glfw3.h>
}

HandleWindow::HandleWindow(unsigned long x, unsigned long y,
    const std::string& s)
    : title(s), win(glfwCreateWindow(x, y, title.c_str(), nullptr, nullptr)) {
    glfwMakeContextCurrent(win);
    glad_value = gladLoadGL(glfwGetProcAddress);
}

bool HandleWindow::operator!(void) const {
    return !glfwWindowShouldClose(win);
}

HandleWindow::operator GLFWwindow* (void) { return win; }

HandleWindow::~HandleWindow(void) { glfwDestroyWindow(win); }
