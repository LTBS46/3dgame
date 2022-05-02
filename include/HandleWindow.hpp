#pragma once

#include "FrameWork.hpp"

struct GLFWwindow;

class HandleWindow final {
    friend Framework;

    protected:
    GLFWwindow* win;
    std::string title;
    int glad_value;
    HandleWindow(unsigned long, unsigned long, const std::string&);

    public:
    ~HandleWindow(void);
    bool operator!(void) const;
    operator GLFWwindow* (void);
    HandleWindow(const HandleWindow&) = delete;
    HandleWindow(HandleWindow&&) = delete;
    HandleWindow& operator=(const HandleWindow&) = delete;
    HandleWindow& operator=(HandleWindow&&) = delete;
};