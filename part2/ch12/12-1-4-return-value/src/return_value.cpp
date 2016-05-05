/*
 * return_value.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

string to_string(int a);
auto to_string(int a) -> string;

template<typename T, typename U>
//auto product(const vector<T>& x, const vector<U>& y) -> decltype(x*y) { return x*y; }
auto product(const vector<T>& x, const vector<U>& y) -> decltype(x[0]*y[0])
{
	decltype(x[0]*y[0]) res { };
	typename vector<T>::const_iterator px;
	typename vector<U>::const_iterator py;

	for (px = x.begin(), py = y.begin();
			px != x.end() && py != y.end(); ++px, ++py)
		res += *px * *py;
	return res;
}

int f1() { }
	// no return statement in function returning non-void [-Wreturn-type]

void f2() { }

int f3() { return 1; }
//void f4() { return 1; }
	// Return has value, in function returning void

//int f5() { return; }
// Return without value, in function returning non-void

void f6() { return; }

int fac(int n)
{
	return (n>1) ? n*fac(n-1) : 1;
}

int fac2(int n)
{
	if (n > 1)
		return n*fac2(n-1);
	return 1;
}

int f() { return 1; }

int* fp()
{
	int local = 1;
		// address of local variable 'local' returned [-Wreturn-local-addr]

	return &local;
}

int& fr()
{
	int local = 2;
		// reference to local variable 'local' returned [-Wreturn-local-addr]

	return local;
}

void g(int* p)
{
	cout << "p: " << p << ", *p: " << *p << '\n';
}

void h(int* p)
{
	return g(p);
}

int main()
{

	//cout << "to_string(123) -> " << to_string(123) << '\n';
		// call of overloaded 'to_string(int)' is ambiguous

	vector<int> vi(5, 2);
	vector<double> vb(5, 3.5);

	auto prod = product(vi, vb);
	cout << prod << '\n';

	cout << "fac(10) -> " << fac(10) << '\n';
	cout << "fac2(10) -> " << fac2(10) << '\n';

	int* p = fp();
	int& r = fr();

	//cout << "*p: " << *p << '\n'; // crash!!!
	//cout << "r: " << r << '\n'; // crash!!!

	int i = 10;
	h(&i);
}

