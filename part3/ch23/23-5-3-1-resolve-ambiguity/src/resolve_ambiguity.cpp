/*
 * resolve_ambiguity.cpp
 *
 *  Created on: 2016/09/16
 *      Author: sasaki
 */


#include <iostream>
#include <typeinfo>
using std::cout;

template<typename T>
T max(T a,T b)
{
	cout << "max<" << typeid(T).name() << ">(" << a << "," << b << ")\n";
	return a < b ? b : a;
}

void f()
{
	max<int>('a', 1);
	max<double>(2.7, 4);
}

inline int max(int i, int j) { return max<int>(i,j); }
inline double max(int i, double d) { return max<double>(i,d); }
inline double max(double d, int i) { return max<double>(d,i); }
inline double max(double d1, double d2) { return max<double>(d1,d2); }

void g()
{
	max('a', 1);
	max(2.7, 4);
}

// add main

int main()
{
	f();
	g();
}
