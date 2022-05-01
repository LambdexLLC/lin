#pragma once

/** @file */

#include <lbx/lin/vec.hpp>
#include <lbx/lin/scalar_math.hpp>

namespace lbx
{
	template <typename T>
	inline T distance(vec<T, 0> a, vec<T, 0> b)
	{
		return static_cast<T>(0);
	};
	template <typename T>
	inline T distance(vec<T, 1> a, vec<T, 1> b)
	{
		return abs(a.x - b.x);
	};
	template <typename T>
	inline T distance(vec<T, 2> a, vec<T, 2> b)
	{
		return distance2(a.x, a.y, b.x, b.y);
	};
	template <typename T>
	inline T distance(vec<T, 3> a, vec<T, 3> b)
	{
		return distance3(a.x, a.y, a.z, b.x, b.y, b.z);
	};

	template <typename T, size_t N>
	inline T length(vec<T, N> _vec)
	{
		return distance(_vec, vec<T, N>());
	};

	template <typename T, size_t N>
	inline vec<T, N> normalize(vec<T, N> _vec)
	{
		const auto l = length(_vec);
		for (auto& v : _vec)
		{
			v /= l;
		};
		return _vec;
	};

	template <typename T>
	inline vec3<T> cross(vec3<T> a, vec3<T> b)
	{
		return vec3<T>
		(
			(a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x)
		);
	};

	template <typename T>
	inline T dot(vec2<T> a, vec2<T> b)
	{
		return (a.x * b.x) + (a.y * b.y);
	};
	template <typename T>
	inline T dot(vec3<T> a, vec3<T> b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	};
	
	template <typename T, size_t N>
	inline T cos(vec<T, N> a, vec<T, N> b)
	{
		const auto d = dot(a, b);
		const auto la = length(a);
		const auto lb = length(b);
		return d / (la * lb);
	};

	template <size_t N>
	inline vec<radians::rep, N> cos(const vec<radians, N>& _vec)
	{
		auto o = vec<radians::rep, N>();
		auto it = _vec.begin();
		for (auto& v : o)
		{
			v = cos(*it++);
		};
		return o;
	};
	template <size_t N>
	inline vec<radians::rep, N> sin(const vec<radians, N>& _vec)
	{
		auto o = vec<radians::rep, N>();
		auto it = _vec.begin();
		for (auto& v : o)
		{
			v = sin(*it++);
		};
		return o;
	};

	template <size_t N>
	inline vec<degrees::rep, N> cos(const vec<degrees, N>& _vec)
	{
		auto o = vec<degrees::rep, N>();
		auto it = _vec.begin();
		for (auto& v : o)
		{
			v = cos(*it++);
		};
		return o;
	};
	template <size_t N>
	inline vec<degrees::rep, N> sin(const vec<degrees, N>& _vec)
	{
		auto o = vec<radians::rep, N>();
		auto it = _vec.begin();
		for (auto& v : o)
		{
			v = sin(*it++);
		};
		return o;
	};

	template <typename T, size_t N>
	inline vec<radians, N> theta(const vec<T, N>& _vec)
	{
		auto _cos = cos(_vec);
		auto _nvIt = _cos.begin();
		auto o = vec3<radians>();
		for (auto& v : o)
		{
			v = acos(*_nvIt++);
		};
		return o;
	};


	template <typename T, size_t N>
	inline radians theta(vec<T, N> a, vec<T, N> b)
	{
		return acos(cos(a, b));
	};
};