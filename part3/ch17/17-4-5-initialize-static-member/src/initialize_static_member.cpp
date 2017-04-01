/*
 * initialize_static_member.cpp
 *
 *  Created on: 2016/07/30
 *      Author: sasaki
 */

#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
	static int node_count;
};

int Node::node_count = 0;


class Curious {
public:
	static const int c1 = 7;
	//static int c2 = 11;
		// error: ISO C++ forbids in-class initialization of non-const static member 'Curious::c2'
	const int c3 = 13;
	static const int c4 = sqrt(9);
	//static const float c5 = 7.0;
		// error: 'constexpr' needed for in-class initialization of static data member 'const float Curious::c5' of non-integral type [-fpermissive]
};

const int Curious::c1;
const int* p = &Curious::c1;

template<typename T, int N>
class Fixed {
public:
	static constexpr int max = N;
private:
	T a[max];
};

class X {
public:
	enum { c1 = 7, c2 = 11, c3 = 13, c4 = 17 };
};


// add main

int main()
{
	cout << "Node::node_count = " << Node::node_count << '\n';

	cout << "Curious::c1 = " << Curious::c1 << '\n';
	cout << "Curious::c4 = " << Curious::c4 << '\n';

	cout << "&Curiouse::c1 = " << &Curious::c1 << '\n';
	cout << "::p = " << p << '\n';

	cout << "Fixed<int,10>::max = " << Fixed<int,10>::max << '\n';

	cout << "X::c1 = " << X::c1 << ", X::c2 = " << X::c2
			<< ", X::c3 = " << X::c3 << ", X::c4 = " << X::c4 << '\n';
}

