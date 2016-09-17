/*
 * template_alias.cpp
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

//#include <vector>
#include <iostream>
#include <memory>
using namespace std;

// custom allocator

template<typename T>
struct My_alloc {
	using value_type = T;

	My_alloc() { }

	T* allocate(size_t n)
		{return reinterpret_cast<T*>(new char[n*sizeof(T)]);}
	void deallocate(T* p, size_t n)
		{ delete[] reinterpret_cast<char*>(p); }
};

// custom vector

template<typename T, typename Allocator=std::allocator<T>>
class vector {
	int sz;
	T* elem;
	Allocator alloc;

public:
	vector(initializer_list<T> il)
	{
		sz = il.size();
		elem = alloc.allocate(sz);
		uninitialized_copy(il.begin(), il.end(), elem);
	}

	~vector() { alloc.deallocate(elem, sz); }

	T* begin() { return elem; }
	const T* begin() const { return elem; }
	T* end() { return elem+sz; }
	const T* end() const { return elem+sz; }
};

// type alias

using Cvec = vector<char>;
Cvec vc = {'a', 'b', 'c'};

// template alias

template<typename T>
using Vec = vector<T,My_alloc<T>>;

Vec<int> fib = {0, 1, 1, 2, 3, 5, 8, 13};

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
	cout << vc << '\n';
	cout << fib << '\n';

	cout << "typeid(a): " << typeid(a).name() << '\n';
	cout << "a: " << a << '\n';
}

