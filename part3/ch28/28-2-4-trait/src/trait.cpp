/*
 * trait.cpp
 *
 *  Created on: 2016/10/05
 *      Author: sasaki
 */

#include <iterator>
#include <vector>
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

template<typename T>
using Value_type = typename std::iterator_traits<T>::value_type;

template<typename T>
using Difference_type = typename std::iterator_traits<T>::difference_type;

template<typename T>
using Iterator_category = typename std::iterator_traits<T>::iterator_category;

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


// add main
int main()
{
	vector<int> vi { 1, 2, 3, 4, 5 };
	int	ai[] = { 1, 2, 3, 4, 5 };

	search(vi.begin(), vi.end(), 3);
	search(&ai[0], &ai[5], 3);

	search2(vi.begin(), vi.end(), 3);
	search2(&ai[0], &ai[5], 3);

	search3(vi.begin(), vi.end(), 3);
	search3(&ai[0], &ai[5], 3);
}
