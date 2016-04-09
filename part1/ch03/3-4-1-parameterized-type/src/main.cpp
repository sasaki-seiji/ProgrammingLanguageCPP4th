/*
 * main.cpp
 *
 *  Created on: 2016/03/27
 *      Author: sasaki
 */

#include <string>
#include <list>
#include <iostream>
#include "Vector.h"

using namespace std;


void write(const Vector<string>& vs)
{
	for(int i = 0; i != vs.size(); ++i)
		cout << vs[i] << '\n';
}

template<typename T>
T* begin(Vector<T>& x)
{
	return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x)
{
	return begin(x) + x.size();
}

void f2(Vector<string>& vs)
{
	for (auto& s : vs)
		cout << s << '\n';
}

int main()
{
	Vector<char> 		vc(200);
	Vector<string>		vs(17);
	Vector<list<int>>	vli(45);

	vs[1] = "this is line 1";
	vs[10] = "this is line 10";

	cout << "calling write(vs)\n";
	write(vs);

	cout << "calling f2(vs)\n";
	f2(vs);

	cout << "for empty vector v2, calling write(v2), f2(v2)\n";
	Vector<string>		vs2(0);
	write(vs2);
	f2(vs2);
}


