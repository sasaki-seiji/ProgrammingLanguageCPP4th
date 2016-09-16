/*
 * overload_and_non_derivating_parameter.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;


template<typename T, typename C>
T get_nth(C& p, int n);


struct Index {
	operator int() { return index; }

	int index;
	Index(int i) : index{i} { }
};

void f(vector<int>& v, short s, Index i)
{
	int i1 = get_nth<int>(v,2);
	int i2 = get_nth<int>(v,s);
	int i3 = get_nth<int>(v,i);

	cout << "i1: " << i1
			<< ", i2: " << i2
			<< ", i3: " << i3 << '\n';
}


// add undef

template<typename T, typename C>
T get_nth(C& p, int n)
{
	return p[n];
}


// add main

int main()
{
	vector<int> v { 0, 1, 2, 3, 4, 5 };
	short s = 3;
	Index i{4};

	f(v, s, i);
}
