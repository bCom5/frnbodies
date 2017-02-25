#pragma once

template<typename T>
struct tvec2 {
	T x, y;
	tvec2(T v = T(0)) : x(v), y(v) {}
	tvec2(T x, T y) : x(x), y(y) {}
	template<typename U>
	tvec2(tvec2<U> v) : x(T(v.x)), y(T(v.y)) {}

};
typedef tvec2<float> vec2;

template<typename T>
inline tvec2<T> operator+ (const tvec2<T>& a, const tvec2<T>& b) {
	return tvec2<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
inline tvec2<T> operator- (const tvec2<T>& a, const tvec2<T>& b) {
	return tvec2<T>(a.x - b.x, a.y - b.y);
}

template<typename T>
inline tvec2<T> operator* (const tvec2<T>& a, const T& b) {
	return tvec2<T>(a.x*b, a.y*b);
}
template<typename T>
inline tvec2<T> operator* (const T& b, const tvec2<T>& a) {
	return tvec2<T>(b*a.x, b*a.y);
}

template<typename T>
inline float length (const tvec2<T>& v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

template<typename T>
inline tvec2<T> to_polar(const tvec2<T>& v) {
	return tvec2<T>(length(v), atan(v.y / v.x);
}

template<typename T>
inline float from_polar(const tvec2<T>& v) {
	return tvec2<T>(x * cos(v.y), x * sin(v.y));
}
