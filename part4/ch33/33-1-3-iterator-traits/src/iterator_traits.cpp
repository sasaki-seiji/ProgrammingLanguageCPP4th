/*
 * iterator_traits.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */

#include "concept.h"
using namespace Estd;

#include <iterator>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

template<typename Iter>
void my_advance_helper(Iter& p, int n, random_access_iterator_tag)
{
	p += n;
}

template<typename Iter>
void my_advance_helper(Iter& p, int n, bidirectional_iterator_tag)
{
	if (0<n)
		while (n--) ++p;
	else if (n<0)
		while (n++) --p;
}

template<typename Iter>
void my_advance(Iter& p, int n)
{
	my_advance_helper(p, n, typename iterator_traits<Iter>::iterator_category{});
}

#if 0
template<typename Iter>
typename Iter::value_type read(Iter p, int n)
	// error: 'int*' is not a class, struct, or union type
{
	return p[n];
}
#else
template<typename Iter>
typename iterator_traits<Iter>::value_type read(Iter p, int n)
{
	return p[n];
}
#endif

template<typename Iter>
void f(Iter p, Iter q)
{
	//Iter::difference_type d1 = distance(p,q);
		// error: need 'typename' before 'Iter:: difference_type' because 'Iter' is a dependent scope
	//typename Iter::difference_type d2 = distance(p,q);
		// error: 'int*' is not a class, struct, or union type
	typename iterator_traits<Iter>::difference_type d3 = distance(p,q);
	//Difference_type<Iter> d4 = distance(p,q);
	Iterator_difference_type<Iter> d4 = distance(p,q);
	auto d5 = distance(p,q);

	cout << "d3: " << d3 << endl;
	cout << "d4: " << d4 << endl;
	cout << "d5: " << d5 << endl;
}

// main
int main()
{
	vector<int> v {1,2,3,4,5,6,7};
	set<int> s {1,2,3,4,5,6,7};

	auto pv1 = v.begin(), pv2{pv1};
	auto ps1 = s.begin(), ps2{ps1};

	advance(pv1, 4);
	cout << "*pv1: " << *pv1 << endl;
	my_advance(pv2, 4);
	cout << "*pv2: " << *pv2 << endl;

	advance(ps1, 5);
	cout << "*ps1: " << *ps1 << endl;
	my_advance(ps2, 5);
	cout << "*ps2: " << *ps2 << endl;

	auto x = read(v.begin(), 2);
	cout << "read(v.begin(),2): " << x << endl;

	int a[7] {1,2,3,4,5,6,7};
	auto y = read(a,2);
	cout << "read(a,2): " << y << endl;

	f(v.begin(), v.end());
	f(a, a+5);
}
