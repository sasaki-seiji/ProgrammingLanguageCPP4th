/*
 * excess_adl.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

// ADL

#include <valarray>
#include <iostream>
using std::valarray;

valarray<double> fct(valarray<double> v1, valarray<double>v2, double d)
{
	std::cout << "-- fct(valarray<double>,valarray<double>,double>) -- \n";
	return v1+v2*d;
}


// excess ADL

#include <vector>
#include <algorithm>
#include <iostream>

namespace User {
	class Customer
	{
		int id;
	public:
		Customer(int i) : id{i} { }
		int get_id() const { return id; }
	};
	using Index = std::vector<Customer*>;

	void copy(const Index& i1, Index& i2, int deep)
	{
		std::cout << "User::copy(const Index&, Index&, int)\n";
	}

	void algo(Index& x, Index& y)
	{
		std::cout << "-- User::algo(Index&,Index&) --\n";

		//copy(x,y,false);
			// error: no type named ‘value_type’ in ‘struct std::iterator_traits<std::vector<User::Customer*> >’
		User::copy(x,y,false);
	}
}

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

template<typename T>
class Display {
public:
	void operator()(const T& x) { std::cout << x << '\n'; }
};

// add main


int main()
{
	valarray<double> v1 {1.1, 2.2, 3.3, 4.4};
	valarray<double> v2 {1.0, 1.0, 2.0, 3.0};
	valarray<double> ans = fct(v1, v2, 0.5);
	for (auto x : ans)
		std::cout << x << ' ';
	std::cout << '\n';

	User::Index c1 {new User::Customer(1), new User::Customer(2)};
	User::Index c2;
	User::algo(c1, c2);

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
