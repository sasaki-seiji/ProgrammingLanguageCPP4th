/*
 * static_assert.cpp
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

static_assert(4<=sizeof(int), "integers are too small");

constexpr double C = 299792.458; // km/s

void f(double speed)
{
	const double local_max = 160.0/(60*60); // 160km/h

	//static_assert(speed < C, "can't go that fast");
		// error: non-constant condition for static assertion
		// error: 'speed' is not a constant expression

	static_assert(local_max < C, "can't go that fast");
}
