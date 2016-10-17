/*
 * user.cpp
 *
 *  Created on: 2016/10/17
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "si_unit.h"

Quantity<M> x {10.9};
Quantity<S> y {20.5};

//Quantity<MpS> s = 0.53;
	// error: conversion from 'double' to non-scalar type 'Quantity<Unit<1, 0, -1> >' requested
Quantity<M> comp(Quantity<M>);

//Quantity<M> n = comp(10.9);
	// error: could not convert '1.09e+1' from 'double' to 'Quantity<Unit<1, 0, 0> >'

Quantity<MpS> speed {0.53};
auto double_speed = Quantity<Unit<0,0,0>>{2}*speed;
auto double_speed2 = 2*speed;

void g()
{
	cout << "double_speed.val: " << double_speed.val << '\n';
	cout << "double_speed2.val: " << double_speed2.val << '\n';
}

void test()
{
	auto distance = 10.9_m;
	auto time = 20.5_s;
	auto speed = distance/time;

	//if (speed == 0.53) { }
		// error: no match for 'operator==' (operand types are 'Quantity<Unit<1, 0, -1> >' and 'double')
	//if (speed == distance) { }
		// error: no match for 'operator==' (operand types are 'Quantity<Unit<1, 0, -1> >' and 'Quantity<Unit<1, 0, 0> >')
	if (speed == 10.9_m/20.5_s) { }

	Quantity<MpS2> acceleration = distance/square(time);
	cout << "speed==" << speed << " acceleration==" << acceleration << '\n';
}

int main()
{
	g();
	test();
}
