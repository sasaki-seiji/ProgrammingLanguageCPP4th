/*
 * reverse_iterator.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */


#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

void f(vector<int>& v, list<char>& lst)
{
	v.rbegin()[3] = 7;
	//lst.rbegin()[3] = '4';
		// error: no match for 'operator-' (operand types are 'const std::_List_iterator<char>' and 'std::reverse_iterator<std::_List_iterator<char> >::difference_type {aka long long int}')
	*(next(lst.rbegin(), 3)) = '4';
}

template<typename C>
void print(ostream& os, const C& c)
{
	for (auto& x : c)
		os << x << ',';
	os << endl;
}

template<typename C, typename Val>
auto find_last(C& c, Val v) -> decltype(c.begin())
{
	auto ri = find(c.rbegin(), c.rend(), v);
	if (ri == c.rend()) return c.end();
	return prev(ri.base());
}

template<typename C, typename Val>
auto find_last2(C& c, Val v) -> decltype(c.begin())
{
	for (auto p = c.rbegin(); p != c.rend(); ++p)
		if (*p == v) return --p.base();
	return c.end();
}

template<typename C, typename Val>
auto find_last3(C& c, Val v) -> decltype(c.begin())
{
	for (auto p = c.end(); p != c.begin(); )
		if (*--p == v) return p;
	return c.end();
}

int main()
{
	vector<int> v {0,1,2,3,4,5};
	list<char> lst {'0', '1', '2', '3', '4', '5'};

	f(v, lst);
	cout << "v: "; print(cout, v);
	cout << "lst: "; print(cout, lst);

	auto p = find_last(v, 3);
	if (p != v.end()) cout << "*p: " << *p << endl;

	p = find_last2(v, 3);
	if (p != v.end()) cout << "*p: " << *p << endl;

	p = find_last3(v, 3);
	if (p != v.end()) cout << "*p: " << *p << endl;
}
