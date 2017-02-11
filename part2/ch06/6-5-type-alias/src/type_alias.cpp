/*
 * type_alias.cpp
 *
 *  Created on: 2016/04/12
 *      Author: sasaki
 */

#include <typeinfo>
#include <vector>
#include <iostream>
using namespace std;

using Pchar = char*;
using PF = int(*)(double);

typedef int int32_t;
typedef short int16_t;
typedef void(*PtoF)(int);

template<typename T>
class My_allocator {

};

template<typename T>
	using Vector = std::vector<T, My_allocator<T>>;

using Char = char;
using Uchar = unsigned Char;	// not error
using Uchar2 = unsigned char;

int main()
{
	cout << "typeid(Pchar) = " << typeid(Pchar).name() << '\n';
	cout << "typeid(PF) = " << typeid(PF).name() << '\n';
	cout << "typeid(int32_t) = " << typeid(int32_t).name() << '\n';
	cout << "typeid(int16_t) = " << typeid(int16_t).name() << '\n';
	cout << "typeid(PtoF) = " << typeid(PtoF).name() << '\n';
	cout << "typeid(Char) = " << typeid(Char).name() << '\n';
	cout << "typeid(Uchar) = " << typeid(Uchar).name() << '\n';
	cout << "typeid(Uchar2) = " << typeid(Uchar2).name() << '\n';

	Pchar p1 = nullptr;
	char* p3 =p1;

	cout << "p1 == p3 ? " << (p1 == p3) << '\n';
}


