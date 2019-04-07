#ifndef DOUBLENUMBERSSUPPORT_H
#define DOUBLENUMBERSSUPPORT_H

#include <cmath>

namespace DoubleCompare
{
	constexpr double DefaultEpsilon{ 0.000001 };

	bool doubleEquals(double left, double right, double epsilon = DefaultEpsilon)
	{
		return (fabs(left - right) < epsilon);
	}
}

#endif

