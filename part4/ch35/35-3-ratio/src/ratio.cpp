/*
 * ratio.cpp
 *
 *  Created on: 2016/12/14
 *      Author: sasaki
 */

#include <ratio>
using namespace std;

int main()
{
	static_assert(ratio_add<ratio<1,3>,ratio<1,6>>::num == 1,
			"problem: 1/3+1/6 != 1/2");
	static_assert(ratio_add<ratio<1,3>,ratio<1,6>>::den == 2,
			"problem: 1/3+1/6 != 1/2");
	static_assert(ratio_multiply<ratio<1,3>,ratio<3,2>>::num == 1,
			"problem: 1/3*3/2 != 1/2");
	static_assert(ratio_multiply<ratio<1,3>,ratio<3,2>>::den == 2,
			"problem: 1/3*3/2 != 1/2");
}

