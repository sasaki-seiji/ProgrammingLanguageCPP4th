/*
 * type_member.cpp
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#include <iostream>
#include <typeinfo>
using namespace std;


template<typename T>
struct X {
	enum E1 { a, b };
	//enum E2;
		//error: use of enum 'E2' without previous declaration
	enum class E3;
	enum E4 : char;

	struct C1 {
		C1() { cout << "X<" << typeid(T).name() << ">::C1::C1()\n"; }
	};
	struct C2;
};

template<typename T>
enum class X<T>::E3 { a, b };

template<typename T>
enum X<T>::E4 : char { x, y };

template<typename T>
struct X<T>::C2 {
	C2() { cout << "X<" << typeid(T).name() << ">::C2::C2()\n"; }
};


// add main

int main()
{
	cout << "X<int>::a: " << X<int>::a << '\n';
	cout << "X<int>::b: " << X<int>::b << '\n';

	cout << "(int)X<int>::E3::a: " << (int)X<int>::E3::a << '\n';
	cout << "(int)X<int>::E3::b: " << (int)X<int>::E3::b << '\n';
		// need cast to (int)

	cout << "X<int>::x: " << X<int>::x << '\n';
	cout << "X<int>::y: " << X<int>::y << '\n';

	X<int>::C1 c1i;
	X<string>::C1 c1s;

	X<int>::C2 c2i;
	X<string>::C2 c2s;
}

