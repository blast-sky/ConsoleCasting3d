#include "ConsoleCasting3d.h"

double ConsoleCasting3d::cast(Vector3d direction)
{
	return 0;
}

bool ConsoleCasting3d::rayIntersect(const Vector3d& dir, double& t0)
{
	Vector3d L = spherePos - pos;
	double tca = L.dotProduct(dir);
	double d2 = L.dotProduct(L) - tca * tca;
	if (d2 > sphereRadius * sphereRadius) return false;
	double thc = std::sqrt(sphereRadius * sphereRadius - d2);
	t0 = tca - thc;
	double t1 = tca + thc;
	if (t0 < 0) t0 = t1;
	if (t0 < 0) return false;
	return true;
}

void ConsoleCasting3d::makeStep()
{
	for (double i = 0; i < w; ++i)
	{
		for (double j = 0; j < h; ++j)
		{
			Vector3d traceDirection = (direction + Vector3d(0, (i / w - 0.5) * iteo, j / h - 0.5)).normalize();

			double dist;
			if (!rayIntersect(traceDirection, dist))
				field[j * w + i] = gradient[0];
			else
			{
				Vector3d norm = pos + traceDirection * dist - spherePos;
				double svetCount = norm.dotProduct(lightDirection);
				if (svetCount < 0) svetCount = 0;
				if (svetCount > 1) svetCount = 1;
				field[j * w + i] = gradient[svetCount * (gradient.size() - 1)];
			}
		}
	}
}
