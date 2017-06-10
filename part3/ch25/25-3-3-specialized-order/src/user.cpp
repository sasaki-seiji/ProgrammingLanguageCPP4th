/*
 * user.cpp
 *
 *  Created on: 2016/09/22
 *      Author: sasaki
 */


#include "Vector.h"

#include <iostream>
using namespace std;

int main()
{
	Vector<int*> vip(10);
	Vector<void*> vvp(10);
	Vector<int> vi(10);

	cout << "typeid(vip): " << typeid(vip).name() << endl;
	cout << "typeid(vvp): " << typeid(vvp).name() << endl;
	cout << "typeid(vi): " << typeid(vi).name() << endl;

}
