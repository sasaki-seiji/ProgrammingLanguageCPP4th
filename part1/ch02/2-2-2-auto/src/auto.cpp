/*
 * auto.cpp
 *
 *  Created on: 2016/03/19
 *      Author: sasaki
 */

#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	auto b = true;
	auto ch = 'x';
	auto i = 123;
	auto d = 1.2;
	//auto z = sqrt(y);
	auto z = sqrt(d);

	// 2016.03.19 add
	cout << "b = " << b << ", ch = " << ch << ", i = " << i
			<< ", d = " << d << ", z = " << z << endl;
}


