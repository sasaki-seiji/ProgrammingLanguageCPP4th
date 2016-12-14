/*
 * type_traits.cpp
 *
 *  Created on: 2016/12/14
 *      Author: sasaki
 */


#include <type_traits>
#include <memory>
#include <complex>
#include <string>
#include <iostream>
using namespace std;

#include "concept.h"
using namespace Estd;

template<typename T>
void f(T& a)
{
	static_assert(std::is_floating_point<T>::value, "FP type expected");
	cout << "T is floating point" << endl;
}

template<typename T>
void f2(T& a)
{
	static_assert(Is_floating_point<T>(), "FP type expected");
	cout << "T is floating point" << endl;
}

template<typename T>
class Cont {
	T* elem;
	size_t sz;
public:
	explicit Cont(size_t n) : elem{new T[n]}, sz{n}
	{
		uninitialized_fill(begin(), end(), T{});
	}

	Cont(const Cont& a) :elem{new T[a.sz]}, sz{a.sz}
	{
		static_assert(Copy_constructible<T>(), "Cont::Cont(): no copy");
		if (Trivially_copyable<T>())
			memcpy(elem, a.elem, sz*sizeof(T));
		else
			uninitialized_copy(a.begin(), a.end(), elem);
	}

	~Cont();

	T* begin() { return &elem[0]; }
	const T* begin() const { return &elem[0]; }
	T* end() { return &elem[sz]; }
	const T* end() const { return &elem[sz]; }
};

template<typename T>
Cont<T>::~Cont()
{
	if (!Trivially_destructible<T>())
		for (T* p = elem; p != elem+sz; ++p)
			p->~T();
}

class X {
public:
	static void inside();
private:
	X& operator=(const X&);
	~X();
};

void X::inside()
{
	cout << "inside =: " << is_copy_assignable<X>::value << '\n';
	cout << "inside ~: " << is_destructible<X>::value << '\n';
}

void outside()
{
	cout << "outside =: " << is_copy_assignable<X>::value << '\n';
	cout << "outside ~: " << is_destructible<X>::value << '\n';
}

template<typename T>
void g(T a)
{
	static_assert(Is_array<T>(), "g(): not an array");
	constexpr int dn {Extent<T,2>()};

	cout << "dn: " << dn << endl;
}

struct Shape {
	virtual void draw() { };
	virtual ~Shape() { }
};
struct Circle : public Shape {
	void draw () override { cout << "Circle::draw()" << endl; }
};

template<typename T>
void draw(T t)
{
	static_assert(Same<Shape*,T>() || Base_of<Shape,Remove_pointer<T>>(), "");
	t->draw();
}

// main

int main()
{
	double d;
	f(d);
	f2(d);

	cout << "Copy_constructible<complex<double>>() ? "
			<< Copy_constructible<complex<double>>() << endl;
	cout << "Trivially_copyable<complex<double>>() ? "
			<< Trivially_copyable<complex<double>>() << endl;
	cout << "Trivially_destructible<complex<double>>() ? "
			<< Trivially_destructible<complex<double>>() << endl;
	Cont<complex<double>> cd1(100);
	Cont<complex<double>> cd2{cd1};

	cout << "Copy_constructible<string>() ? "
			<< Copy_constructible<string>() << endl;
	cout << "Trivially_copyable<string>() ? "
			<< Trivially_copyable<string>() << endl;
	cout << "Trivially_destructible<string>() ? "
			<< Trivially_destructible<string>() << endl;
	Cont<string> cs1(100);
	Cont<string> cs2{cs1};

	X::inside();
	outside();

	int arr[3][4][5];
	//g(arr);
	g<int[3][4][5]>(arr);

	Circle circle;
	draw(&circle);
}
