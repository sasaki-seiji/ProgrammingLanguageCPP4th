/*
 * output_process.cpp
 *
 *  Created on: 2016/12/25
 *      Author: sasaki
 */


#include <iostream>
#include <complex>
using namespace std;

void print_val(char ch)
{
	cout << "The value of '" << ch << "' is " << int{ch} << '\n';
}

void test()
{
	print_val('a');
	print_val('A');
}

template<typename T>
struct Named_val {
	string name;
	T value;
};

template<typename T>
ostream& operator<<(ostream& os, const Named_val<T>& nv)
{
	return os << '{' << nv.name << ':' << nv.value << '}';
}

int main()
{
	test();

	Named_val<int> nvi = {"nvi", 101};
	cout << nvi << endl;

	Named_val<complex<double>> nvc = {"nvc", {-10, 3.4}};
	cout << nvc << endl;
}
