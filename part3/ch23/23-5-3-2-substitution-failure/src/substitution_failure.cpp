/*
 * substitution_failure.cpp
 *
 *  Created on: 2016/09/16
 *      Author: sasaki
 */


#include <vector>
#include <iostream>
using namespace std;

// substitution failure

template<typename Iter>
typename Iter::value_type mean(Iter first, Iter last);

void f(vector<int>& v, int* p, int n)
{
	cout << "-- f(vector<int>&,int*,int) --\n";

	auto x = mean(v.begin(), v.end());
	//auto y = mean(p, p+n);
		// error: no matching function for call to 'mean(int*&, int*)'

	cout << "x: " << x << '\n';
}

// partially substitution failure

template<typename T>
T mean(T*,T*);

void g(vector<int>& v, int* p, int n)
{
	cout << "-- g(vector<int>&,int*,int) --\n";

	auto x = mean(v.begin(), v.end());
	auto y = mean(p, p+n);

	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
}

// fails on instanciation

template<typename Iter>
Iter mean_at(Iter first, Iter last)
{
	using Val = typename Iter::value_type;
	Val m = mean(first, last);

	while (first != last) {
		if (*first == m) return first;
		++first;
	}

	return last;
}

template<typename T>
T* mean_at(T* first, T* last)
{
	T m = mean(first, last);

	while (first != last) {
		if (*first == m) return first;
		++first;
	}

	return last;
}

void h(vector<int>& v, int* p, int n)
{
	cout << "-- h(vector<int>&, int*, int) --\n";

	auto x = mean_at(v.begin(), v.end());
	auto y = mean_at(p, p+n);

	cout << "*x: " << *x << '\n';
	cout << "*y: " << *y << '\n';
}


// add undef

template<typename Iter>
typename Iter::value_type mean(Iter first, Iter last)
{
	typedef typename Iter::value_type V;

	V m{};
	int c = 0;
	for ( ; first != last; ++first, ++c )
		m += *first;

	return m/c;
}

template<typename T>
T mean(T* first, T* last)
{
	T m{};
	int c = 0;
	for ( ; first != last; ++first, ++c )
		m += *first;

	return m/c;
}


// add main

int main()
{
	vector<int> v { 2, 4, 1, 6, 2, 3, 9, -2};
	int arr[] = { 2, 4, 1, 6, 2, 3, 9, -2 };
	int sz = sizeof(arr)/sizeof(arr[0]);

	f(v, arr, sz);
	g(v, arr, sz);
	h(v, arr, sz);
}
