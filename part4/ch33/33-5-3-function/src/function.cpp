/*
 * function.cpp
 *
 *  Created on: 2016/12/04
 *      Author: sasaki
 */


#include <functional>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int f1(double);
function<int(double)> fct {f1};
int f2(int);
int f3(char*);

void user()
{
	cout << "-- user() --\n";

	fct = [](double d) { return round(d); };
	cout << "fct(7.6): " << fct(7.6) << endl;

	fct = f1;
	cout << "fct(7.6): " << fct(7.6) << endl;

	fct = f2;
	cout << "fct(7.6): " << fct(7.6) << endl;

	//fct = f3;
		// error: no match for 'operator=' (operand types are 'std::function<int(double)>' and 'int(char*)')
}

int round2(double x) { return static_cast<int>(floor(x+0.5)); }

function<int(double)> f;

enum class Round_style { truncate, round };

struct Round {
	Round_style s;
	Round(Round_style ss) :s(ss) { }
	int operator()(double x) const
		{ return static_cast<int>((s==Round_style::round) ? (x+0.5) : x); }
};

void t1()
{
	cout << "-- t1() --\n";

	f = round2;
	cout << f(7.6) << '\n';

	f = Round(Round_style::truncate);
	cout << f(7.6) << '\n';

	Round_style style = Round_style::round;
	f = [style](double x)
		{ return static_cast<int>((style==Round_style::round) ? x+0.5 : x); };
	cout << f(7.6) << '\n';

	vector<double> v {7.6};
	f = Round(Round_style::round);
	std::transform(v.begin(), v.end(), v.begin(), f);
	cout << v[0] << '\n';
}

// undefs

int f1(double d)
{
	cout << "f1(" << d << ")\n";
	return static_cast<int>(round(d));
}

int f2(int i)
{
	cout << "f2(" << i << ")\n";
	return i;
}

// main

int main()
{
	user();
	t1();
	return 0;
}
