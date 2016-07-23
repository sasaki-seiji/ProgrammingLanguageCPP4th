/*
 * user.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include "Vector.h"
#include <iostream>
using namespace std;

struct S {
	S();
	//void S(int);
		// return type specification for constructor invalid
	//int S;
		// field 'int S::S' with same name as class [-fpermissive]
	//enum S { foo, bar };
		// 'S::S' has the same name as the class in which it is declared
};

int main()
{
	Vector v1(10);
	cout << "v1.size(): " << v1.size() << '\n';

	Vector v2(0);
	cout << "v2.size(): " << v2.size() << '\n';

	try {
		Vector v3(-1);
		cout << "v3.size(): " << v3.size() << '\n';
	}
	catch (Bad_size& e) {
		cout << "Bad_size occurred. size: " << e.size() << '\n';
	}
}
