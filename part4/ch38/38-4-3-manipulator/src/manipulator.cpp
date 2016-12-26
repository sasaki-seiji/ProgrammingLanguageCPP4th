/*
 * manipulator.cpp
 *
 *  Created on: 2016/12/26
 *      Author: sasaki
 */


#include <iostream>
#include <iomanip>
using namespace std;

struct smanip {
	ios_base& (*f)(ios_base&,int);
	int i;
	smanip(ios_base&(*ff)(ios_base&,int), int ii) : f{ff}, i{ii} { }
};

template<typename C, typename Tr>
basic_ostream<C,Tr>& operator<<(basic_ostream<C,Tr>& os, const smanip& m)
{
	m.f(os, m.i);
	return os;
}

inline smanip my_setprecision(int n)
{
	auto h = [](ios_base& s, int x) -> ios_base& { s.precision(x); return s; };
	return smanip(h, n);
}

int main()
{
	double angle = 123.456789;

	cout << setprecision(4) << angle << endl;
	cout << my_setprecision(4) << angle << endl;
}
