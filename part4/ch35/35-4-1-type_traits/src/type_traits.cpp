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

// is_floating_point

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

// is_copy_constructible, is_trivially_copyable

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
		static_assert(Is_copy_constructible<T>(), "Cont::Cont(): no copy");
		if (Is_trivially_copyable<T>())
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

// is_trivially_destructible

template<typename T>
Cont<T>::~Cont()
{
	if (!Is_trivially_destructible<T>())
		for (T* p = elem; p != elem+sz; ++p)
			p->~T();
}

// do not check access control

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

// extent

template<typename T>
void f3(T a)
{
	static_assert(Is_array<T>(), "f3(): not an array");
	constexpr int dn {Extent<T,2>()};

	cout << "dn: " << dn << endl;
}

// is_same, is_base_of

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
	static_assert(Is_same<Shape*,T>() || Is_base_of<Shape,Remove_pointer<T>>(), "");
	t->draw();
}

// main

int main()
{
	cout << "-- is_floating_point --\n";
	double d;
	f(d);
	f2(d);

	cout << "-- is_copy_constructible, is_trivially_copyable, is_trivially_destructible --\n";

	cout << "Is_copy_constructible<complex<double>>() ? "
			<< Is_copy_constructible<complex<double>>() << endl;
	cout << "Is_trivially_copyable<complex<double>>() ? "
			<< Is_trivially_copyable<complex<double>>() << endl;
	cout << "Is_trivially_destructible<complex<double>>() ? "
			<< Is_trivially_destructible<complex<double>>() << endl;
	Cont<complex<double>> cd1(100);
	Cont<complex<double>> cd2{cd1};

	cout << "Is_copy_constructible<string>() ? "
			<< Is_copy_constructible<string>() << endl;
	cout << "Is_trivially_copyable<string>() ? "
			<< Is_trivially_copyable<string>() << endl;
	cout << "Is_trivially_destructible<string>() ? "
			<< Is_trivially_destructible<string>() << endl;
	Cont<string> cs1(100);
	Cont<string> cs2{cs1};

	cout << "-- type check and access constrol --\n";

	X::inside();
	outside();

	cout << "-- extent --\n";

	int arr[3][4][5];
	//f3(arr);
	f3<int[3][4][5]>(arr);

	cout << "-- is_same, is_base_of --\n";

	Circle circle;
	draw(&circle);
}
