/*
 * type_equality.cpp
 *
 *  Created on: 2016/09/10
 *      Author: sasaki
 */

#include "String.h"
#include <typeinfo>
#include <vector>
using namespace std;

String<char> s1;
String<unsigned char> s2;
String<int> s3;

using Uchar = unsigned char;
using uchar = unsigned char;

String<Uchar> s4;
String<uchar> s5;
String<char> s6;

template<typename T, int N>
class Buffer { };

Buffer<String<char>, 10> b1;
Buffer<char, 10> b2;
Buffer<char, 20-10> b3;


struct Shape {
	virtual ~Shape() { }
};
struct Circle : public Shape {
};

// add main

int main()
{
	cout << "String<char> s1;             " << typeid(s1).name() << '\n';
	cout << "String<unsigned char> s2;    " << typeid(s2).name() << '\n';
	cout << "String<int> s3;              " << typeid(s3).name() << '\n';
	cout << "String<Uchar> s4;            " << typeid(s4).name() << '\n';
	cout << "String<uchar> s5;            " << typeid(s5).name() << '\n';
	cout << "String<char> s6;             " << typeid(s6).name() << '\n';

	cout << "Buffer<String<char>,10> b1;  " << typeid(b1).name() << '\n';
	cout << "Buffer<char,10> b2;          " << typeid(b2).name() << '\n';
	cout << "Buffer<char,20-10> b3;       " << typeid(b3).name() << '\n';

	Shape *ps { new Circle{} };
	//vector<Shape> *pvs { new vector<Circle>{} };
		// error: cannot convert 'std::vector<Circle>*' to 'std::vector<Shape>*' in initialization
	//vector<Shape> vs { vector<Circle>{} };
		// error: no matching function for call to 'std::vector<Shape>::vector(<brace-enclosed initializer list>)'
	//vector<Shape*> vps { vector<Circle*>{ } };
		// error: no matching function for call to 'std::vector<Shape*>::vector(<brace-enclosed initializer list>)'
}


