/*
 * initialize_by_constructor.cpp
 *
 *  Created on: 2016/07/25
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;


struct S1 {
	int a,b;
};


struct S2 {
	int a,b;
	S2(int aa = 0, int bb = 0) : a(aa), b(bb) {}
};

void f()
{
	//S1 x11(1,2);
		// error: no matching function for call to 'S1::S1(int, int)'
	S1 x12 {1,2};

	//S1 x13(1);
		//  error: no matching function for call to 'S1::S1(int)'
	S1 x14 {1};

	S2 x21(1,2);
	S2 x22 {1,2};

	S2 x23(1);
	S2 x24 {1};

	cout << "x12.a: " << x12.a << ", x12.b: " << x12.b << '\n';
	cout << "x14.a: " << x14.a << ", x14.b: " << x14.b << '\n';

	cout << "x21.a: " << x21.a << ", x21.b: " << x21.b << '\n';
	cout << "x22.a: " << x22.a << ", x22.b: " << x22.b << '\n';

	cout << "x23.a: " << x23.a << ", x23.b: " << x23.b << '\n';
	cout << "x24.a: " << x24.a << ", x24.b: " << x24.b << '\n';
}


vector<string> v1 {77};

vector<string> v2(77);

vector<string> v3 {"Booh!"};
//vector<string> v4("Booh!");
	// error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(const char [6])'

vector<int*> v5 {100,0};

vector<int*> v6 {0,0};
vector<int*> v7(0,0);
vector<int*> v8;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "size:" << v.size();
	for (auto x : v) {
		os << "," << x ;
	}
	return os;
}

// add main

int main()
{
	f();

	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;
	cout << "v3: " << v3 << endl;
	cout << "v5: " << v5 << endl;
	cout << "v6: " << v6 << endl;
	cout << "v7: " << v7 << endl;
	cout << "v8: " << v8 << endl;
}
