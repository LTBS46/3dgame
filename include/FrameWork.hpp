#pragma once

#include "FW_fwd.hpp"

#include <string>
#include <map>
#include <functional>

using ErrorCallback = std::function<void(int, const char*)>;

enum class WindowFlags : long {
    Visible = 0b1,
    Focused = 0b10,
    Resizable = 0b100,
    Decorated = 0b1000,
    Maximized = 0b10000
};

constexpr WindowFlags operator|(WindowFlags f1, WindowFlags f2) {
    return (WindowFlags) (((long) f1) | (long) f2);
}


class Framework final {
    protected:
    Framework(void);
    ~Framework(void);

    public:
    Framework(const Framework&) = delete;
    Framework(Framework&&) = delete;
    Framework& operator=(const Framework&) = delete;
    Framework& operator=(Framework&&) = delete;
    static Framework& get_instance(void);
    operator bool(void) const noexcept;
    bool operator!(void) const noexcept;
    const std::string& get_version_string(void) const;
    static bool reinit(bool = false);
    HandleWindow* new_window(unsigned long x, unsigned long y,
        const std::string& s = "New Window",
        WindowFlags f = WindowFlags::Visible |
        WindowFlags::Focused);

    protected:
    bool status;
    ErrorCallback default_error_callback;
    std::map<int, ErrorCallback> error_callbacks;

    struct {
        int maj, min, rev;
        std::string str;
    } version;
    static void error_callback(int, const char*);
    static Framework* instance;
};