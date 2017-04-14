/*
 * user.cpp
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */


#include "Action.h"
#include "Add.h"

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void f(Action act)
{
	cout << "--f(Action) --\n";

	int x = act(2);
	auto y = act(2,4);
	double z = act(2.3);

	cout << "x: " << x << '\n';
	cout << "y.first: " << y.first << ", y.second: " << y.second << '\n';
	cout << "z: " << z << '\n';
}


void h(vector<complex<double>>& vec, list<complex<double>>& lst, complex<double> z)
{
	cout << "--h(vector<complex<double>>&,list<comple<double>>&,complex) --\n";

	for_each(vec.begin(), vec.end(), Add{2,3});
	for_each(lst.begin(), lst.end(), Add{z});
}

void h2(vector<complex<double>>& vec, list<complex<double>>& lst, complex<double> z)
{
	cout << "-- h2(vector<complex<double>>&,list<complex<double>>&,complex) --\n";

	//for_each(vec.begin(), vec.end(),[](complex<double>& a){ a+={2,3}; });
	for_each(vec.begin(), vec.end(),[](complex<double>& a){ a+=complex<double>{2,3}; });
		// error: no match for 'operator+=' (operand types are 'std::complex<double>' and '<brace-enclosed initializer list>')
	//for_each(lst.begin(), lst.end(),[](complex<double>& a){ a+=z; });
	for_each(lst.begin(), lst.end(),[z](complex<double>& a){ a+=z; });
		// error: 'z' is not captured
}

ostream& operator<<(ostream& os, const vector<complex<double>>& v)
{
	os << "[ ";
	for (auto x : v)
		os << x << " ";
	os << "]";
	return os;
}

ostream& operator<<(ostream& os, const list<complex<double>>& v)
{
	os << "( ";
	for (auto x : v)
		os << x << " ";
	os << ")";
	return os;
}

// add main

int main()
{
	Action act;
	f(act);

	vector<complex<double>> vec;
	list<complex<double>> lst;

	for (int i = 0; i < 5; ++i) {
		complex<double> z = complex<double>(i,i);
		vec.push_back(z);
		lst.push_back(z);
	}
	h(vec, lst, {0,1});
	cout << "vec: " << vec << '\n';
	cout << "list: " << lst << '\n';

	h2(vec, lst, {0,1});
	cout << vec << '\n';
	cout << lst << '\n';
}
