/*
 * user.cpp
 *
 *  Created on: 2017/05/31
 *      Author: sasaki
 */


#include "si_unit.h"
#include <iostream>
using namespace std;

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
//auto increated_speed = 2.3 + speed;
	// error: no match for ‘operator+’ (operand types are ‘double’ and ‘Quantity<Unit<1, 0, -1> >’)

int main()
{
	cout << "x.val: " << x.val << endl;
	cout << "y.val: " << y.val << endl;
	cout << "double_speed.val: " << double_speed.val << endl;
	cout << "double_speed2.val: " << double_speed2.val << endl;
}



