/*
 * template_difinition_check.cpp
 *
 *  Created on: 2016/10/29
 *      Author: sasaki
 */

#include "input_iterator.h"
#include "equality_comparable.h"
#include "iterator_traits.h"
using namespace Estd;

#include <list>
#include <vector>
#include <iostream>

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
	static_assert(Input_iterator<Iter>(), "find() requires an input iterator");
	static_assert(Equality_comparable<Value_type<Iter>,Val>(),
			"find()'s iterator and value arguments must match");

	while (b!=e) {
		if (*b==x) return b;
#if 0
		b = b+1;
#else
		++b;
#endif
	}
	return b;
}

void f(std::list<int>& lst, std::vector<std::string>& vs)
{
	std::cout << "-- f(std::list<int>&,std::vector<std::string>&) --\n";

	auto p = find(lst.begin(), lst.end(), 1209);
	auto q = find(vs.begin(), vs.end(), "Cambridge");

	std::cout << "*p: " << *p << '\n';
	std::cout << "*q: " << *q << '\n';
}

template<typename Val>
//struct Forward {
struct Forward : public std::iterator<std::forward_iterator_tag, Val> {
	Val v;
	Forward() = default;
	Forward(const Forward&) = default;
	Forward& operator=(const Forward&) = default;
	bool operator==(const Forward& o) { return true; } // should be const
	bool operator!=(const Forward& o) { return false; }
	void operator++() { }
	void operator++(int) { }
	Val& operator*() { return v; }
};

template<typename Val>
struct Input : public std::iterator<std::input_iterator_tag, Val> {
	Val v;
	Input() = default;
	Input(const Input&) = default;
	Input& operator=(const Input&) = default;
	bool operator==(const Input& o) { return true; }
	bool operator!=(const Input& o) { return false; }
	void operator++() { }
	void operator++(int) { }
	Val& operator*() { return v; }
};


// cannot specialize alias-template
#if 0
template<typename Val>
using Value_type<Forward<Val>> = Val;
	// error: expected '=' before '<' token
#endif

void g()
{
	std::cout << "-- g() --\n";
	std::cout << std::boolalpha;

	Forward<int> p = find(Forward<int>{},Forward<int>{},7);
	std::cout << "not found: " << (p == Forward<int>{}) << '\n';

	Input<int> q = find(Input<int>{},Input<int>{},7);
	std::cout << "not found: " << (q == Input<int>{}) << '\n';
}

void test_constraint()
{
	std::cout << "-- test_constraint() --\n";
	std::cout << std::boolalpha;

	bool b1 = Has_iterator_category<Forward<int>>();
	bool b2 = Convertible<Iterator_category_result<Forward<int>>, std::input_iterator_tag>();
	bool b3 = Has_dereference<Forward<int>>();
	bool b4 = Has_iterator_value_type<Forward<int>>();
	bool b5 = Convertible<Dereference_result<Forward<int>>,Iterator_value_type_result<Forward<int>>>();
	bool b6 = Has_pre_increment<Forward<int>>();
	bool b7 = Has_post_increment<Forward<int>>();
	bool b8 = Has_equal<Forward<int>>();
	bool b9 = Has_not_equal<Forward<int>>();

	std::cout << "Has_iterator_category<Forward<int>>(): " << b1 << '\n';
	std::cout << "Convertible<Iterator_category_result<Forward<int>>, std::input_iterator_tag>(): " << b2 << '\n';
	std::cout << "Has_dereference<Forward<int>>(): " << b3 << '\n';
	std::cout << "Has_iterator_value_type<Forward<int>>(): " << b4 << '\n';
	std::cout << "Convertible<Dereference_result<Forward<int>>,Iterator_value_type_result<Forward<int>>>(): " << b5 << '\n';
	std::cout << "Has_pre_increment<Forward<int>>(): " << b6 << '\n';
	std::cout << "Has_post_increment<Forward<int>>(): " << b7 << '\n';
	std::cout << "Has_equal<Forward<int>>(): " << b8 << '\n';
	std::cout << "Has_not_equal<Forward<int>>(): " << b9 << '\n';
}

// add main

int main()
{
	std::list<int> lst {1,2,40,1209};
	std::vector<std::string> vs {"here", "is", "Cambridge", "city"};

	f(lst,vs);

	g();
	test_constraint();
}

