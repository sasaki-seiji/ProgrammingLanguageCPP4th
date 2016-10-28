/*
 * template_difinition_check.cpp
 *
 *  Created on: 2016/10/29
 *      Author: sasaki
 */

#include "concept.h"
using namespace Estd;

#include <list>
#include <vector>

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
	bool operator==(const Forward& o) { return true; }
	bool operator!=(const Forward& o) { return false; }
	void operator++() { }
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
	Forward<int> p = find(Forward<int>{},Forward<int>{},7);
	std::cout << "not found: " << (p == Forward<int>{}) << '\n';

	Input<int> q = find(Input<int>{},Input<int>{},7);
	std::cout << "not found: " << (q == Input<int>{}) << '\n';
}

// add main

int main()
{
	std::list<int> lst {1,2,40,1209};
	std::vector<std::string> vs {"here", "is", "Cambridge", "city"};

	f(lst,vs);

	g();
}





