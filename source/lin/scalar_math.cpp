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


	float distance2(float x0, float y0, float x1, float y1)
	{
		return std::hypot(x0 - x1, y0 - y1);
	};
	float distance3(float x0, float y0, float z0, float x1, float y1, float z1)
	{
		return std::hypot(x0 - x1, y0 - y1, z0 - z1);
	};
	double distance2(double x0, double y0, double x1, double y1)
	{
		return std::hypot(x0 - x1, y0 - y1);
	};
	double distance3(double x0, double y0, double z0, double x1, double y1, double z1)
	{
		return std::hypot(x0 - x1, y0 - y1, z0 - z1);
	};
	long double distance2(long double x0, long double y0, long double x1, long double y1)
	{
		return std::hypot(x0 - x1, y0 - y1);
	};
	long double distance3(long double x0, long double y0, long double z0, long double x1, long double y1, long double z1)
	{
		return std::hypot(x0 - x1, y0 - y1, z0 - z1);
	};

	float distance2_squared(float x0, float y0, float x1, float y1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1);
	};
	float distance3_squared(float x0, float y0, float z0, float x1, float y1, float z1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1) + pow2(z0 - z1);
	};
	double distance2_squared(double x0, double y0, double x1, double y1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1);
	};
	double distance3_squared(double x0, double y0, double z0, double x1, double y1, double z1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1) + pow2(z0 - z1);
	};
	long double distance2_squared(long double x0, long double y0, long double x1, long double y1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1);
	};
	long double distance3_squared(long double x0, long double y0, long double z0, long double x1, long double y1, long double z1)
	{
		return pow2(x0 - x1) + pow2(y0 - y1) + pow2(z0 - z1);
	};

	float sqrt(float v)
	{
		return std::sqrt(v);
	};
	double sqrt(double v)
	{
		return std::sqrt(v);
	};
	long double sqrt(long double v)
	{
		return std::sqrt(v);
	};

	float cbrt(float v)
	{
		return std::cbrt(v);
	};
	double cbrt(double v)
	{
		return std::cbrt(v);
	};
	long double cbrt(long double v)
	{
		return std::cbrt(v);
	};

	float pow(float v, float p)
	{
		return std::pow(v, p);
	};
	double pow(double v, double p)
	{
		return std::pow(v, p);
	};
	long double pow(long double v, long double p)
	{
		return std::pow(v, p);
	};

	float pow2(float v)
	{
		return lbx::pow(v, 2);
	};
	double pow2(double v)
	{
		return lbx::pow(v, 2);
	};
	long double pow2(long double v)
	{
		return lbx::pow(v, 2);
	};
};