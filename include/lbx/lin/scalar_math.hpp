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

	float distance2_squared(float x0, float y0, float x1, float y1);
	float distance3_squared(float x0, float y0, float z0, float x1, float y1, float z1);
	double distance2_squared(double x0, double y0, double x1, double y1);
	double distance3_squared(double x0, double y0, double z0, double x1, double y1, double z1);
	long double distance2_squared(long double x0, long double y0, long double x1, long double y1);
	long double distance3_squared(long double x0, long double y0, long double z0, long double x1, long double y1, long double z1);

	float distance2(float x0, float y0, float x1, float y1);
	float distance3(float x0, float y0, float z0, float x1, float y1, float z1);
	double distance2(double x0, double y0, double x1, double y1);
	double distance3(double x0, double y0, double z0, double x1, double y1, double z1);
	long double distance2(long double x0, long double y0, long double x1, long double y1);
	long double distance3(long double x0, long double y0, long double z0, long double x1, long double y1, long double z1);

	float sqrt(float v);
	double sqrt(double v);
	long double sqrt(long double v);

	float cbrt(float v);
	double cbrt(double v);
	long double cbrt(long double v);

	float pow(float v, float p);
	double pow(double v, double p);
	long double pow(long double v, long double p);

	float pow2(float v);
	double pow2(double v);
	long double pow2(long double v);
};