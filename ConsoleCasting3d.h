#pragma once

#include <string>
#include <cmath>

class ConsoleCasting3d
{
private:
	struct Vector3d
	{
		double x, y, z;

		Vector3d(double coord) : x(coord), y(coord), z(coord) {};
		Vector3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};

		Vector3d operator+(const Vector3d& other)
		{
			return Vector3d(x + other.x, y + other.y, z + other.z);
		}
		Vector3d operator-(const Vector3d& other) const
		{
			return Vector3d(x - other.x, y - other.y, z - other.z);
		}
		Vector3d operator*(double size) const
		{
			return Vector3d(x * size, y * size, z * size);
		}
		Vector3d operator/(double size) const
		{
			return Vector3d(x / size, y / size, z / size);
		}

		double dotProduct(const Vector3d& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}
		Vector3d normalize() const
		{
			double size = std::sqrt(dotProduct(*this));
			return *this / size;
		}
	};

private:
	const std::string gradient = " .,:;#@";
	Vector3d spherePos = { 0,0,0 };
	double sphereRadius = 1;

	const int w, h;
	const double iteo;

	Vector3d pos = { -3, 0, 0 };
	Vector3d direction = { 1, 0, 0 };

public:
	std::string field;
	Vector3d lightDirection = { 0, 0, -1 };

private:
	double cast(Vector3d direction); // returns distance to closely figure // to do
	bool rayIntersect(const Vector3d& dir, double& t0);

public:
	ConsoleCasting3d(int w = 120, int h = 30) :
		w(w), h(h), iteo((double(w)/h)/2)
	{ field.resize(w * h); };

	void makeStep();

};

