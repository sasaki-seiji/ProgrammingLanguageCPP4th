/*
 * user.cpp
 *
 *  Created on: 2017/05/31
 *      Author: sasaki
 */

#include "si_unit.h"
#include <iostream>
using namespace std;

int main()
{
	auto distance = 10.9_m;
	auto time = 20.5_s;
	auto speed = distance/time;

	//if (speed == 0.53) { }
		// error: no match for ‘operator==’ (operand types are ‘Quantity<Unit<1, 0, -1> >’ and ‘double’)
	//if (speed == distance) { }
		// error: no match for ‘operator==’ (operand types are ‘Quantity<Unit<1, 0, -1> >’ and ‘Quantity<Unit<1, 0, 0> >’)
	if (speed == 10.9_m/20.5_s) { cout << "speed == 10.9_m/20.5_s" << endl; }

	Quantity<MpS2> acceleration = distance/square(time);

	cout << "speed=" << speed << " acceleration=" << acceleration << endl;
}

