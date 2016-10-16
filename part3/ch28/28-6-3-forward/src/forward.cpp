/*
 * forward.cpp
 *
 *  Created on: 2016/10/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename F, typename... T>
void call(F&& f, T&&... t)
{
	f(forward<T>(t)...);
}

void g0()
{
	cout << "g0()\n";
}

template<typename T>
void g1(const T& t)
{
	cout << "g1(): " << t << '\n';
}

void g1d(double t)
{
	cout << "g1d(): " << t << '\n';
}

template<typename T, typename T2>
void g2(const T& t, T2&& t2)
{
	cout << "g2(): " << t << ' ' << t2 << '\n';
}

void test()
{
	call(g0);
	//call(g1);
		// error: no matching function for call to 'call(<unresolved overloaded function type>)'
	call(g1<int>,1);
	call(g1<const char*>,"hello");
	call(g1<double>,1.2);
	call(g1d,1.2);
	//call(g1d,"No way!");
		// error: cannot convert 'const char*' to 'double' in argument passing
	//call(g1d,1.2,"I can't count");
		// error: too many arguments to function
	call(g2<double,string>,1,"world!");
	int i = 99;
	const char* p = "Trying";
	call(g2<double,string>,i,p);
	call([](){ cout << "l1()\n"; });
	call([](int i){ cout << "l0(): " << i << "\n"; }, 17);
	call([i](){ cout << "l1(): " << i << "\n"; });
}

// add main

int main()
{
	test();
}
