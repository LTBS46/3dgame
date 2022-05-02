#include "FrameWork.hpp"
#include "HandleWindow.hpp"
extern "C" {
#include <GLFW/glfw3.h>
}
#include <utility>

using std::string;
using std::pair;

Framework* Framework::instance = new Framework;

void Framework::error_callback(int i, const char* c) {
    auto& a = get_instance();
    auto& b = a.error_callbacks;
    b.count(i) ? b[i](i, c) : a.default_error_callback(i, c);
}

Framework::Framework(void) {
    version.str = glfwGetVersionString();
    glfwGetVersion(&version.maj, &version.min, &version.rev);
    auto a = glfwSetErrorCallback(error_callback);
    status = glfwInit();
    if (status) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    }
}

const string& Framework::get_version_string(void) const {
    return version.str;
}

Framework& Framework::get_instance(void) { return *instance; }

Framework::operator bool(void) const noexcept { return status; }

bool Framework::operator!(void) const noexcept {
    return !(bool) (*this);
}

Framework::~Framework(void) {
    if (*this) glfwTerminate();
}

bool Framework::reinit(bool b) {
    if (b || !*instance) {
        delete instance;
        instance = new Framework();
        return *instance;
    }
    return true;
}

HandleWindow* Framework::new_window(unsigned long x, unsigned long y,
    const string& s,
    WindowFlags f) {
    using pflag = pair<WindowFlags, int>;
    long l = (long) f;
    for (auto [wflag, flag_glfw] :
        { pflag(WindowFlags::Visible, GLFW_VISIBLE),
         pflag(WindowFlags::Focused, GLFW_FOCUSED),
         pflag(WindowFlags::Resizable, GLFW_RESIZABLE),
         pflag(WindowFlags::Decorated, GLFW_DECORATED),
         pflag(WindowFlags::Maximized, GLFW_MAXIMIZED) })
        glfwWindowHint(flag_glfw, (l & (long) wflag) ? GLFW_TRUE : GLFW_FALSE);
    return new HandleWindow(x, y, s);
}