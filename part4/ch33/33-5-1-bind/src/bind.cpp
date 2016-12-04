/*
 * bind.cpp
 *
 *  Created on: 2016/12/04
 *      Author: sasaki
 */


#include <functional>
#include <iostream>
using namespace std;

double cube(double);

void test1()
{
	cout << "-- test1() --\n";

	auto cube2 = bind(cube, 2);

	auto res = cube2();
	cout << "cube2() returns: " << res << endl;
}

using namespace placeholders;
void f(int,const string&);

void test2()
{
	cout << "-- test2() --\n";

	auto g = bind(f,2,_1);
	f(2,"hello");
	g("hello");
}

void test3()
{
	cout << "-- test3() --\n";

	f(2, "hello");
	//bind(f)(2,"hello");
		// error: static assertion failed: Wrong number of arguments for function
	bind(f, _1, _2)(2, "hello");
	bind(f, _2, _1)("hello", 2);

	auto g = [](const string& s, int i) { f(i, s); };
	g("hello", 2);
}

#include <cmath>
int pow(int,int);
double pow(double,double);

void test4()
{
	cout << "-- test4() --\n";

	//auto pow2 = bind(pow, _1, 2);
		// error: no matching function for call to 'bind(<unresolved overloaded function type>, const std::_Placeholder<1>&, int)'
	auto pow2d = bind((double(*)(double,double))pow, _1, 2);

	auto res = pow2d(2.3);
	cout << "pow2d(2.3) returns: " << res << endl;
}

void incr(int& i)
{
	++i;
}

void user()
{
	cout << "-- user() --\n";

	int i = 1;
	incr(i);
	cout << "i: " << i << endl;

	auto inc = bind(incr, _1);
	inc(i);
	cout << "i: " << i << endl;
}

void user2()
{
	cout << "-- user2() --\n";

	int i = 1;
	incr(i);
	cout << "i: " << i << endl;

	auto inc = bind(incr, _1);
	inc(ref(i));
	cout << "i: " << i << endl;
}

void user_modified()
{
	cout << "-- user_modified() --\n";

	int i = 1;
	incr(i);
	cout << "i: " << i << endl;

	auto inc = bind(incr, i);
	inc();
	cout << "i: " << i << endl;
}

void user2_modified()
{
	cout << "-- user2_modified() --\n";

	int i = 1;
	incr(i);
	cout << "i: " << i << endl;

	auto inc = bind(incr, ref(i));
	inc();
	cout << "i: " << i << endl;
}

// undefs

double cube(double x)
{
	return x*x*x;
}

void f(int i,const string& s)
{
	cout << "f(int:" << i << ",const string&:\"" << s << "\")" << endl;
}

// main

int main()
{
	test1();
	test2();
	test3();
	test4();

	user();
	user2();
	user_modified();
	user2_modified();
}
