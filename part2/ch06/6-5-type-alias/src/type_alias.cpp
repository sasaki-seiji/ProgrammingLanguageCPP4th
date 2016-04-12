/*
 * type_alias.cpp
 *
 *  Created on: 2016/04/12
 *      Author: sasaki
 */

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
	using vector = std::vector<T, My_allocator<T>>;

using Char = char;
//using Uchar = unsigned Char;
using Uchar = unsigned char;

int main()
{
	Pchar p1 = nullptr;
	char* p3 =p1;

	cout << "p1 == p3 ? " << (p1 == p3) << '\n';
}


