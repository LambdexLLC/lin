#include <lbx/lin/scalar_math.hpp>

#include <cmath>

namespace lbx
{
	float cos(radians_unit<float> v)
	{
		return std::cos(v.count());
	};
	float sin(radians_unit<float> v)
	{
		return std::sin(v.count());
	};
	float tan(radians_unit<float> v)
	{
		return std::tan(v.count());
	};
	double cos(radians_unit<double> v)
	{
		return std::cos(v.count());
	};
	double sin(radians_unit<double> v)
	{
		return std::sin(v.count());
	};
	double tan(radians_unit<double> v)
	{
		return std::tan(v.count());
	};
	long double cos(radians_unit<long double> v)
	{
		return std::cos(v.count());
	};
	long double sin(radians_unit<long double> v)
	{
		return std::sin(v.count());
	};
	long double tan(radians_unit<long double> v)
	{
		return std::tan(v.count());
	};

	float cos(degrees_unit<float> v)
	{
		return cos(radians(v));
	};
	float sin(degrees_unit<float> v)
	{
		return sin(radians(v));
	};
	float tan(degrees_unit<float> v)
	{
		return tan(radians(v));
	};
	double cos(degrees_unit<double> v)
	{
		return cos(radians_unit<double>(v));
	};
	double sin(degrees_unit<double> v)
	{
		return sin(radians_unit<double>(v));
	};
	double tan(degrees_unit<double> v)
	{
		return tan(radians_unit<double>(v));
	};
	long double cos(degrees_unit<long double> v)
	{
		return cos(radians_unit<long double>(v));
	};
	long double sin(degrees_unit<long double> v)
	{
		return sin(radians_unit<long double>(v));
	};
	long double tan(degrees_unit<long double> v)
	{
		return tan(radians_unit<long double>(v));
	};

	radians_unit<float> acos(float v)
	{
		return radians(std::acos(v));
	};
	radians_unit<float> asin(float v)
	{
		return radians(std::asin(v));
	};
	radians_unit<float> atan(float v)
	{
		return radians(std::atan(v));
	};
	radians_unit<double> acos(double v)
	{
		return radians_unit<double>(std::acos(v));
	};
	radians_unit<double> asin(double v)
	{
		return radians_unit<double>(std::asin(v));
	};
	radians_unit<double> atan(double v)
	{
		return radians_unit<double>(std::atan(v));
	};
	radians_unit<long double> acos(long double v)
	{
		return radians_unit<long double>(std::acos(v));
	};
	radians_unit<long double> asin(long double v)
	{
		return radians_unit<long double>(std::asin(v));
	};
	radians_unit<long double> atan(long double v)
	{
		return radians_unit<long double>(std::atan(v));
	};
};