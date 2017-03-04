/*
 * return_value.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

string my_to_string(int a);
auto my_to_string(int a) -> string;

template<typename T, typename U>
//auto product(const vector<T>& x, const vector<U>& y) -> decltype(x*y) { return x*y; }
auto product(const vector<T>& x, const vector<U>& y) -> decltype(x[0]*y[0])
{
	cout << "-- product(const vector<" << typeid(T).name()
			<< ">&, const vector<" << typeid(U).name() << ">&) -> "
			<< typeid(decltype(x[0]*y[0])).name() << " --\n";

	decltype(x[0]*y[0]) res { };
	typename vector<T>::const_iterator px;
	typename vector<U>::const_iterator py;

	for (px = x.begin(), py = y.begin();
			px != x.end() && py != y.end(); ++px, ++py)
		res += *px * *py;
	return res;
}

int f1() { }
	// warning: no return statement in function returning non-void [-Wreturn-type]

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
		// warning: address of local variable 'local' returned [-Wreturn-local-addr]

	return &local;
}

int& fr()
{
	int local = 2;
		// warning: reference to local variable 'local' returned [-Wreturn-local-addr]

	return local;
}

void g(int* p)
{
	cout << "g(int*: " << *p << ")\n";
}

void h(int* p)
{
	cout << "h(int*: " << *p << ")\n";
	return g(p);
}

int main()
{

	cout << "my_to_string(123) -> " << my_to_string(123) << endl;

	vector<int> vi(7, 2);
	vector<double> vb(7, 3.3);

	auto prod = product(vi, vb);
	cout << prod << endl;

	cout << "fac(10) -> " << fac(10) << endl;
	cout << "fac2(10) -> " << fac2(10) << endl;

	int* p = fp();
	int& r = fr();

	//cout << "*fp() = " << *p << '\n'; // crash!!!, terminated on Ubuntu
	//cout << "fr() = " << r << '\n'; // crash!!!, terninated on Ubuntu

	int i = 10;
	h(&i);
}

// undef

string my_to_string(int x)
{
	return std::to_string(x);
}
