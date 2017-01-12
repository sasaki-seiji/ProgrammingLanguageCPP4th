/*
 * constructor_and_assignment.cpp
 *
 *  Created on: 2017/01/12
 *      Author: sasaki
 */


#include <valarray>
#include <iostream>
using namespace std;

void test_constructor()
{
	valarray<double> v0;
	valarray<float> v1(1000);
	valarray<int> v2(-1,2000);
	valarray<double> v3(100,9.8064);
	valarray<double> v4 = v3;
	valarray<int> v5 = {-1,2000};

	cout << "v0.size()=" << v0.size() << endl;
	cout << "v1.size()=" << v1.size() << endl;
	cout << "v2.size()=" << v2.size() << endl;
	cout << "v3.size()=" << v3.size() << endl;
	cout << "v4.size()=" << v4.size() << endl;
	cout << "v5.size()=" << v5.size() << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const valarray<T>& va)
{
	for (auto x : va)
		os << x << ',';
	return os;
}

void f(const int* p, int n)
{
	const double vd[] = {0,1,2,3,4};
	const int vi[] = {0,1,2,3,4};

	valarray<double> v1{vd,4};
	//valarray<double> v2{vi,4};
		// error: no matching function for call to ‘std::valarray<double>::valarray(<brace-enclosed initializer list>)’
	valarray<double> v3{vd,8};
	valarray<int> v4{p,n};	// warning: from int to size_t

	cout << "v1=" << v1 << endl;
	cout << "v3=" << v3 << endl;
	cout << "v4=" << v4 << endl;
}

void test_assign()
{
	valarray<int> v {1,2,3,4,5,6,7,8};
	v *= 2;
	cout << "v=" << v << endl;
	v = 7;
	cout << "v=" << v << endl;
}

int main()
{
	test_constructor();

	const int v[] = {0,1,2,3,4,5};
	f(v,6);

	test_assign();
}
