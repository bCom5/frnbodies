#pragma once

template<typename T>
struct tvec2 {
	T x, y;
	tvec2(T v = T(0)) : x(v), y(v) {}
	tvec2(T x, T y) : x(x), y(y) {}
	template<typename U>
	tvec2(tvec2<U> v) : x(T(v.x)), y(T(v.y)) {}

	// polar ? need help
	T r, theta;
	tvec2(T v = T(0) : r(v), theta(v) {}
	tvec2(T r, T theta) : r(r), theta(theta) {}
	template<typename U>
	tvec2(tvec2<U> v) : : r(T(v.r), theta(T(v.theta)) {}
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

// what to do for polar here?