/*
 * user.cpp
 *
 *  Created on: 2016/10/11
 *      Author: sasaki
 */


#include <vector>
#include <complex>
#include <iostream>
using namespace std;

#include "concept.h"
using namespace Estd;


template<typename T>
Enable_if<Ordered<T>()> fct(T*,T*)
{
	cout << "Ordered\n";
}

template<typename T>
Enable_if<!Ordered<T>()> fct(T*,T*)
{
	cout << "!Ordered\n";
}

void f(vector<int>& vi, vector<complex<int>>&vc)
{
	if (vi.size()==0 || vc.size()==0) throw runtime_error("bad fct arg");
	fct(&vi.front(), &vi.back());
	fct(&vc.front(), &vc.back());
}

// add main

int main()
{
	vector<int> vi {1, 2, 3};
	vector<complex<int>> vc {{1, -1}, {-2, 0}, {2, -1}};
	f(vi,vc);

#if 0 // for debug
	cout << "Ordered<int>()? " << Ordered<int>() << '\n';
	cout << "Regular<int>()? " << Regular<int>() << '\n';
	cout << "Semiregular<int>()? " << Semiregular<int>() << '\n';
	cout << "Equality_comparable<int,int>()? " << Equality_comparable<int,int>() << '\n';
	cout << "Has_equals<int,int>()? " << Has_equals<int,int>() << '\n';
#endif
}
