/*
 * search.h
 *
 *  Created on: 2017/05/26
 *      Author: sasaki
 */


#ifndef SEARCH_H_
#define SEARCH_H_

#include "iterator_traits.h"
using namespace Estd;

#include <iterator>
#include <iostream>
using namespace std;

template<typename Iter>
Iter search(Iter p, Iter q, typename iterator_traits<Iter>::value_type val)
{
	typename iterator_traits<Iter>::difference_type m = q - p;
	cout << "search - m: " << m << '\n';

	for ( ; p!=q; ++p )
		if (*p==val) {
			cout << "search - found: " << *p << '\n';
			return p;
		}

	return q;
}

template<typename Iter>
Iter search2(Iter p, Iter q, Value_type<Iter> val)
{
	Difference_type<Iter> m = q - p;
	cout << "search2 - m: " << m << '\n';

	for ( ; p!=q; ++p )
		if (*p==val) {
			cout << "search2 - found: " << *p << '\n';
			return p;
		}

	return q;
}

template<typename Iter, typename Val>
Iter search3(Iter p, Iter q, Val val)
{
	auto x = *p;
	auto m = q - p;
	cout << "search3 - x: " << x << '\n';
	cout << "search3 - m: " << m << '\n';

	using value_type = decltype(*p);
	using difference_type = decltype(q-p);
	value_type x2 = *p;
	difference_type m2 = q-p;
	cout << "search3 - x2: " << x2 << '\n';
	cout << "search3 - m2: " << m2 << '\n';

	for ( ; p!=q; ++p )
		if (*p==val) {
			cout << "search3 - found: " << *p << '\n';
			return p;
		}

	return q;
}




#endif /* SEARCH_H_ */
