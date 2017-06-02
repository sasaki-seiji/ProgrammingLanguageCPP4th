/*
 * explicit_using_declaration.cpp
 *
 *  Created on: 2017/06/03
 *      Author: sasaki
 */

// using declaration

#include <iterator>

template<typename Range, typename Op>
void apply(const Range& r, Op f)
{
	using std::begin;
	using std::end;
	for (auto& x : r)
		f(x);
}

// 2016.09.24: why work well?
template<typename Range, typename Op>
void apply2(const Range& r, Op f)
{
	for (auto& x : r)
		f(x);
}

#include <algorithm>

template<typename Range, typename Op>
void apply3(const Range& r, Op f)
{
	auto b = begin(r);
	auto e = end(r);
	for_each(b, e, f);
}

template<typename Range, typename Op>
void apply4(const Range& r, Op f)
{
	using std::begin;
	using std::end;
	using std::for_each;

	auto b = begin(r);
	auto e = end(r);
	for_each(b, e, f);
}

#include <iostream>

template<typename T>
class Display {
public:
	void operator()(const T& x) { std::cout << x << '\n'; }
};


// add main


int main()
{
	std::vector<double> vd {1.1, 2.2, 3.3, 4.4 };
	int arr[] = { 1, 2, 3 };

	std::cout << "-- apply(vector<double>&)\n";
	apply(vd, Display<double>());
	std::cout << "-- apply(int (&)[3])\n";
	apply(arr, Display<int>());

	std::cout << "-- apply2(vector<double>&)\n";
	apply2(vd, Display<double>());
	std::cout << "-- apply2(int (&)[3])\n";
	apply2(arr, Display<int>());

	std::cout << "-- apply3(vector<double>&)\n";
	apply3(vd, Display<double>());
	std::cout << "-- apply3(int (&)[3])\n";
	//apply3(arr, Display<int>());
		// error: ‘begin’ was not declared in this scope

	std::cout << "-- apply4(vector<double>&)\n";
	apply4(vd, Display<double>());
	std::cout << "-- apply4(int (&)[3])\n";
	apply4(arr, Display<int>());
}



