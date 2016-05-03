/*
 * call_and_return.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

void f(double x) { cout << "f(" << x << ")\n"; }

void g(double y)
{
	auto z0 = [&]{ f(y); };
	auto z1 = [=](int x){ return x+y; };
	auto z2 = [y]{ if (y) return 1; else return 2; };
	auto z3 = [y](){ return (y) ? 1 : 2; };
	auto z4 = [y]()->int { if (y) return 1; else return 2; };

	cout << "z0()->void\n"; z0();
	cout << "z1(2)->" << z1(2) << '\n';
	cout << "z2()->" << z2() << '\n';
	cout << "z3()->" << z3() << '\n';
	cout << "z4()->" << z4() << '\n';

}
int main()
{
	g(1.5);
	g(0.0);
}

