/*
 * enable_if.cpp
 *
 *  Created on: 2016/10/08
 *      Author: sasaki
 */

#include <type_traits>
#include <complex>
#include <iostream>
using namespace std;

template<bool B, typename T = void>
struct my_enable_if {
	typedef T type;
};

template<typename T>
struct my_enable_if<false,T> { };

template<bool B, typename T =void>
using My_enable_if = typename my_enable_if<B,T>::type;

template<typename T>
constexpr bool Is_class()
{
	return std::is_class<T>::value;
}

template<typename T>
class Smart_pointer {
	T *p;
public:
	Smart_pointer(T* pp) : p{pp} { }
	T& operator*() { return *p; }
	template<typename U=T>
		My_enable_if<Is_class<U>(),U>* operator->() { return p; }
};

void f(Smart_pointer<double> p, Smart_pointer<complex<double>> q)
{
	auto d0 = *p;
	auto c0 = *q;
	auto d1 = q->real();
	//auto d2 = p->real();
		// base operand of '->' has non-pointer type 'Smart_pointer<double>'

	cout << "d0: " << d0 << '\n';
	cout << "c0: " << c0 << '\n';
	cout << "d1: " << d1 << '\n';
}

// add main

int main()
{
	double pp = 1.2;
	complex<double> qq = {2.3, 4.5};
	Smart_pointer<double> p(&pp);
	Smart_pointer<complex<double>> q(&qq);
	f(p,q);
}
