
template <class T>
struct Vector2 final {
    T x, y;
    constexpr Vector2(const T& t) : x(t), y(t) { }
    constexpr Vector2(void) : x(0), y(0) { }
};

template <class T>
struct Vector3 final {
    T x, y, z;
    constexpr Vector3(const T& t) : x(t), y(t), z(t) { }
    constexpr Vector3(void) : x(0), y(0), z(0) { }
};

template <class T>
struct Vector4 final {
    T x, y, z, w;
    constexpr Vector4(const T& t) : x(t), y(t), z(t), w(t) { }
    constexpr Vector4(void) : x(0), y(0), z(0), w(0) { }
};

using vec2 = Vector2<float>;
using vec3 = Vector3<float>;
using vec4 = Vector4<float>;