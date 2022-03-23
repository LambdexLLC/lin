#pragma once
#ifndef LBX_LIN_VEC3_HPP
#define LBX_LIN_VEC3_HPP

#include <lbx/lin/vec.hpp>

namespace lbx
{
	template <typename T>
	using vec3 = vec<T, 3>;
	
	using uvec3 = vec<unsigned, 3>;
	using ivec3 = vec<int, 3>;
	using fvec3 = vec<float, 3>;
	using dvec3 = vec<double, 3>;





};

#endif // LBX_LIN_VEC3_HPP