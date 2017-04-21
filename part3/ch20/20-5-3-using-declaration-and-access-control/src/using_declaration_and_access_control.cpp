/*
 * using_declaration_and_access_control.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class B {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class D : public B {
public:
	//using B::a;
		// error: 'int B::a' is private
	using B::b;
};

class BB : private B {
public:
	using B::b;
//	using B::c;
};

// add main

int main()
{
	D d;
	d.b = 23;
	cout << "d.b: " << d.b << '\n';

	BB bb;
	bb.b = 34;
//	bb.c = 45;
	cout << "bb.b: " << bb.b << '\n';
}

