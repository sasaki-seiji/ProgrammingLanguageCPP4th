/*
 * lambda_implementation_model.cpp
 *
 *  Created on: 2016/05/02
 *      Author: sasaki
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print_modulo(const vector<int>& v, ostream& os, int m)
{
	cout << "-- print_modulo(const vector<int>&,ostream&, int:" << m << ") --\n";

	for_each(begin(v), end(v),
			[&os,m](int x){ if (x%m==0) os << x << '\n'; }
	);
}

class Modulo_print {
	ostream& os;
	int m;
public:
	Modulo_print(ostream& s, int mm) :os(s), m(mm) {}
	void operator()(int x) const
		{ if (x % m == 0) os << x << '\n'; }
};

void print_modulo2(const vector<int>& v, ostream& os, int m)
{
	cout << "-- print_modulo2(const vector<int>&,ostream&, int:" << m << ") --\n";

	for_each(begin(v), end(v), Modulo_print{os,m});
}

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; ++i)
		v.push_back(i);

	print_modulo(v, cout, 17);
	print_modulo2(v, cout, 19);
}

