/*
 * user.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */


#include "complex.h"
#include <iostream>
using namespace std;


complex<float> cf;
complex<double> cd {cf};
complex<float> cf2 {cd};

complex<float> cf3 {2.0, 3.0};
complex<double> cd2 {2.0F, 3.0F};



// add main

int main()
{
	cout << "cf: " << cf << '\n';
	cout << "cd: " << cd << '\n';
	cout << "cf2: " << cf2 << '\n';

	cout << "cf3: " << cf3 << '\n';
	cout << "cd2: " << cd2 << '\n';
}

