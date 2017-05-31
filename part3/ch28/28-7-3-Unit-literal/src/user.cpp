/*
 * user.cpp
 *
 *  Created on: 2017/05/31
 *      Author: sasaki
 */


#include "si_unit.h"
#include <iostream>
#include <typeinfo>
using namespace std;

void use_quantity_value()
{
	cout << "-- use_quantity_value() --\n";

	auto distance = Quantity<M>{10.9};
	auto time = Quantity<S>{20.5};
	auto speed = distance/time;

	cout << "distance.val: " << distance.val << endl;
	cout << "time.val: " << time.val << endl;
	cout << "speed.val: " << speed.val << endl;

	cout << "typeid(distance): " << typeid(distance).name() << endl;
	cout << "typeid(time): " << typeid(time).name() << endl;
	cout << "typeid(speed): " << typeid(speed).name() << endl;
}

void use_double_literal()
{
	cout << "-- use_double_literal() --\n";

	auto distance = 10.9;
	auto time = 20.5;
	auto speed = distance/time;

	cout << "distance: " << distance << endl;
	cout << "time: " << time << endl;
	cout << "speed: " << speed << endl;
}

void use_quantity_literal()
{
	cout << "-- use_double_literal() --\n";

	auto distance = 10.9_m;
	auto time = 20.5_s;
	auto speed = distance/time;

	cout << "distance.val: " << distance.val << endl;
	cout << "time.val: " << time.val << endl;
	cout << "speed.val: " << speed.val << endl;

	cout << "typeid(distance): " << typeid(distance).name() << endl;
	cout << "typeid(time): " << typeid(time).name() << endl;
	cout << "typeid(speed): " << typeid(speed).name() << endl;
}

void use_several_literal()
{
	cout << "-- use_several_literal() --\n";

	auto km = 12.34_km;
	auto g = 12.34_g;
	auto mg = 12.34_mg;
	auto ms = 12.34_ms;
	auto us = 12.34_us;
	auto ns = 12.34_ns;

	cout << "km.val: " << km.val << endl;
	cout << "g.val: " << g.val << endl;
	cout << "mg.val: " << mg.val << endl;
	cout << "ms.val: " << ms.val << endl;
	cout << "us.val: " << us.val << endl;
	cout << "ns.val: " << ns.val << endl;
}
int main()
{
	use_quantity_value();
	use_double_literal();
	use_quantity_literal();
	use_several_literal();
}
