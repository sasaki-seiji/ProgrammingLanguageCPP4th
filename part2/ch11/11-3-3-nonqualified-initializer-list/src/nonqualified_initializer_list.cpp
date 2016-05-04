/*
 * nonqualified_initializer_list.cpp
 *
 *  Created on: 2016/05/01
 *      Author: sasaki
 */

#include <limits>
#include <vector>
#include <iostream>
using namespace std;

class Matrix {
public:
	int& operator[](pair<int,int>index) { return value; }
private:
	int value {10};
};

int f(double d, Matrix& m)
{
	int v {7};
	int v2 = {7};
	int v3 = m[{2,3}];

	v = {8};
	//v += {88};
		// invalid operands of types 'int' and '<brace-enclosed initializer list>' to binary 'operator+'

	//{v} = 9;
		// expected ';' before '}' token

	//v = 7+{10};
		// expected primary-expression before '{' token

	if (d != 10.0) f({10.0}, m);

	cout << "v: " << v << '\n';
	cout << "v2: " << v2 << '\n';
	cout << "v3: " << v3 << '\n';

	return {11};
}

int high_value(initializer_list<int> val)
{
	//int high = numeric_traits<int>::lowest();
	int high = numeric_limits<int>::lowest();
	if (val.size() == 0) return high;

	for (auto x : val)
		if (x > high) high = x;

	return high;
}

template<typename T>
void f(T);

void f()
{
	//auto x0 = {};
		// unable to deduce 'std::initializer_list<_Tp>' from '{1, 2.0e+0}'
	auto x1 = {1};
	auto x2 = {1, 2};
	auto x3 = {1, 2, 3};
	//auto x4 = {1, 2.0};
		// unable to deduce 'std::initializer_list<_Tp>' from '<brace-enclosed initializer list>()'	nonqualified_initializer_list.cpp	/11-3-3-nonqualified-initializer-list/src	行 58	C/C++ 問題

	cout << is_same<decltype(x1), initializer_list<int>>::value << '\n';
	cout << is_same<decltype(x2), initializer_list<int>>::value << '\n';
	cout << is_same<decltype(x3), initializer_list<int>>::value << '\n';

	//f({});
	//f({1});
	//f({1, 2});
	//f({1, 2, 3});
		// no matching function for call to 'f(<brace-enclosed initializer list>)'
}

template<typename T>
void f2(const vector<T>& v)
{
	cout << "[ ";
	for (auto& x : v)
		cout << x << ' ';
	cout << "]\n";
}

int main()
{
	Matrix m;
	int retval = f(5.1, m);

	cout << "f(5.1, m) returns " << retval << '\n';

	int v1 = high_value({1,2,3,4,5,6,7});
	int v2 = high_value({-1,2,v1,4,-9,20,v1});

	cout << "v1: " << v1 << '\n';
	cout << "v2: " << v2 << '\n';

	f();

	//f2({1, 2, 3});
	//f2({"Kona", "Sidney"});
		// no matching function for call to 'f2(<brace-enclosed initializer list>)'

	f2(vector<int>{1,2,3});
	f2(vector<string>{"kona","Sidney"});
}


