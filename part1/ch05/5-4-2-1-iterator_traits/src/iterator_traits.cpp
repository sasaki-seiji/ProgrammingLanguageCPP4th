/*
 * iterator_traits.cpp
 *
 *  Created on: 2016/04/06
 *      Author: sasaki
 */

#include <vector>
#include <forward_list>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename C>
using Value_type = typename C::value_type;

template<typename C>
using Iterator_type = typename C::iterator;

template<typename Iter>
using Iterator_category = typename iterator_traits<Iter>::iterator_category;

template<typename Ran>
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)
{
	sort(beg, end);
}

template<typename For>
void sort_helper(For beg, For end, forward_iterator_tag)
{
	vector<Value_type<For>> v {beg, end};
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), beg);
}

template<typename C>
void sort(C& c)
{
	using Iter = Iterator_type<C>;
	sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
}

void test(vector<string>& v, forward_list<int>& lst)
{
	sort(v);
	sort(lst);
}

template<typename C>
void print_values(const C& c)
{
	for (auto& x : c)
		cout << x << '\n';
}

int main()
{
	vector<string> v = {"this", "is", "a", "string", "vector" };
	forward_list<int> lst = { 3, 4, 1, 7, 2, 4 };

	test(v, lst);

	print_values(v);
	print_values(lst);
}
