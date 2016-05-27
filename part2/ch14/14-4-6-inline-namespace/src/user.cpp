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

#if 0
template<typename T>
class Popular::C<T*> { };
	// specialization of 'template<class T> class Popular::V3_2::C' in different namespace [-fpermissive]
#else
namespace Popular {
	template<typename T>
	class C<T*> { };
}
#endif

int main()
{
	f();
}
