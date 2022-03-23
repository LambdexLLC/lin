#pragma once

#include <lbx/lin/unit.hpp>

namespace lbx
{
	float cos(radians_unit<float> v);
	float sin(radians_unit<float> v);
	float tan(radians_unit<float> v);
	double cos(radians_unit<double> v);
	double sin(radians_unit<double> v);
	double tan(radians_unit<double> v);
	long double cos(radians_unit<long double> v);
	long double sin(radians_unit<long double> v);
	long double tan(radians_unit<long double> v);

	float cos(degrees_unit<float> v);
	float sin(degrees_unit<float> v);
	float tan(degrees_unit<float> v);
	double cos(degrees_unit<double> v);
	double sin(degrees_unit<double> v);
	double tan(degrees_unit<double> v);
	long double cos(degrees_unit<long double> v);
	long double sin(degrees_unit<long double> v);
	long double tan(degrees_unit<long double> v);

	radians_unit<float> acos(float v);
	radians_unit<float> asin(float v);
	radians_unit<float> atan(float v);
	radians_unit<double> acos(double v);
	radians_unit<double> asin(double v);
	radians_unit<double> atan(double v);
	radians_unit<long double> acos(long double v);
	radians_unit<long double> asin(long double v);
	radians_unit<long double> atan(long double v);
};