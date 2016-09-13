/*
 * friend_class.cpp
 *
 *  Created on: 2016/09/13
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename T>
class My_other_class;

class C;
using C2 = C;

template<typename T>
class My_class {
	friend C;
	friend C2;
	//friend C3;
		// error: 'C3' does not name a type
	friend class C4;

public:
	int get_other_val(My_other_class<T>& o)
	{
		return o.val;
	}
};

template<typename T>
class My_other_class {
	friend T;
	friend My_class<T>;
	//friend class T;
		// error: using template type parameter 'T' after 'class'

	int val = 10;
};

class C {
public:
	int get_other_val(My_other_class<C>& o)
	{ return o.val; }
};
// add main

int main()
{
	My_other_class<C> other;
	C c;
	cout << "access My_other_class<C> from C: " << c.get_other_val(other) << '\n';
	My_class<C> mycls;
	cout << "access My_ohter_class<C> from My_class<C>: " << mycls.get_other_val(other) << '\n';
}

