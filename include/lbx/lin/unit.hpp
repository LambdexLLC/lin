#pragma once

#include <lbx/lin/detail/basic_unit.hpp>
#include <lbx/lin/detail/number.hpp>


namespace lbx
{
	struct radians_tag {};
	
	template <typename T>
	using radians_unit = basic_unit<T, radians_tag>;
	using radians = radians_unit<float>;

	namespace literals
	{
		constexpr radians operator""_rad(long double v)
		{
			return radians(static_cast<radians::rep>(v * pi_v<long double>));
		};
		constexpr radians operator""_rad(long long unsigned v)
		{
			return radians(static_cast<radians::rep>((long double)v * pi_v<long double>));
		};
	};
};

namespace lbx
{
	struct degrees_tag {};

	template <typename T>
	using degrees_unit = basic_unit<T, degrees_tag>;

	using degrees = degrees_unit<float>;

	namespace literals
	{
		constexpr degrees operator""_deg(long double v)
		{
			return degrees(static_cast<degrees::rep>(v));
		};
		constexpr degrees operator""_deg(long long unsigned v)
		{
			return degrees(static_cast<degrees::rep>(v));
		};
	};
};

namespace lbx
{
	template <typename T>
	struct unit_cast_t<degrees_unit<T>, radians_unit<T>>
	{
		constexpr static radians_unit<T> implicit_cast(const degrees_unit<T>& v)
		{
			return radians_unit<T>((v.count() / T(180)) * pi_v<T>);
		};
	};
	template <typename T>
	struct unit_cast_t<radians_unit<T>, degrees_unit<T>>
	{
		constexpr static degrees_unit<T> implicit_cast(const radians_unit<T>& v)
		{
			return degrees_unit<T>((v.count() / pi_v<T>) * T(2));
		};
	};
};

