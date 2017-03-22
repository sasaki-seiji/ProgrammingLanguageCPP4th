/*
 * user.cpp
 *
 *  Created on: 2016/05/28
 *      Author: sasaki
 */


#include <iostream>
#include "Popular.h"

using namespace Popular;

void f()
{
	f(1);
	V3_0::f(1);
	V2_4_2::f(1);
}

template<typename T>
class Popular::C<T*> {
public:
	C() { std::cout << "Popular::C<T*>::C()\n"; }
};

int main()
{
	f();
	Popular::C<char*> c;
}


