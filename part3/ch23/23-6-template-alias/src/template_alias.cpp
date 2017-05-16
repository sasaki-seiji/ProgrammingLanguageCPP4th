/*
 * template_alias.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include <memory>
using namespace std;

// custom allocator

template<typename T>
struct My_alloc {
	using value_type = T;

	My_alloc() { }

	T* allocate(size_t n)
		{ return reinterpret_cast<T*>(::operator new(n*sizeof(T))); }
	void deallocate(T* p, size_t n)
		{ ::operator delete(p); }
};

// type alias

using Cvec = vector<char>;
Cvec vc = {'a', 'b', 'c'};

// template alias

template<typename T>
using Vec = vector<T,My_alloc<T>>;

Vec<int> fib = {0, 1, 1, 2, 3, 5, 8, 13};

vector<char,allocator<char>> vc2 = vc;
vector<int,My_alloc<int>> verbose = fib;

// equality between original template and template alias

template<int>
struct int_exact_traits {
	using type = int;
};

template<>
struct int_exact_traits<8> {
	using type = char;
};
template<>
struct int_exact_traits<16> {
	using type = short;
};

template<int N>
using int_exact = typename int_exact_traits<N>::type;

int_exact<8> a = 7;


// utility

template<typename T, typename A>
ostream& operator<<(ostream& os, const vector<T,A>& v)
{
	for (auto x : v)
		os << x << ' ';
	return os;
}

// add undef

// add main

int main()
{
	cout << boolalpha;
	cout << "vc: " << vc << '\n';
	cout << "fib: " << fib << '\n';
	cout << "vc2: " << vc2 << endl;
	cout << "verbose: " << verbose << endl;
	cout << "vc2 == vc ? " << (vc2 == vc) << endl;
	cout << "verbose == fib ? " << (verbose == fib) << endl;

	cout << "typeid(a): " << typeid(a).name() << '\n';
	cout << "(int)a: " << (int)a << '\n';
}

