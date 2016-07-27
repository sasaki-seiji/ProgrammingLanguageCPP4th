/*
 * vague_of_initializer_list_constructor.cpp
 *
 *  Created on: 2016/07/27
 *      Author: sasaki
 */

#include <initializer_list>
#include <iostream>
#include <vector>
using namespace std;

struct X {
	X(initializer_list<int>);
	X();
	X(int);
};

X x0 {};
X x1 {1};


vector<int> v1 {1};
vector<int> v2 {1,2};
vector<int> v3 {1,2,3};

vector<string> vs1 {"one"};
vector<string> vs2 {"one", "two"};
vector<string> vs3 {"one", "two", "three"};

vector<int> v11(1);
vector<int> v21(1,2);


// add utilities

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[";
	for (auto x : v)
		os << x << ",";
	os << "]";
	return os;
}

// add undef-func

X::X()
{
	cout << "X::X()\n";
}

X::X(initializer_list<int> args)
{
	cout << "X::X({";
	for (auto x : args)
		cout << x << ',';
	cout << "})\n";
}

X::X(int x)
{
	cout << "X::X(" << x << ")\n";
}


// add main

int main()
{
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;

	cout << vs1 << endl;
	cout << vs2 << endl;
	cout << vs3 << endl;

	cout << v11 << endl;
	cout << v21 << endl;
}
