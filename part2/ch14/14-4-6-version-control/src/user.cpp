/*
 * user.cpp
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */


#include "Popular.h"

using namespace Popular;

void f()
{
	f(1);
	V3_0::f(1);
	V2_4_2::f(1);
}

namespace Popular {
	template<typename T>
	class C<T*> { };
}

int main()
{
	f();
}


