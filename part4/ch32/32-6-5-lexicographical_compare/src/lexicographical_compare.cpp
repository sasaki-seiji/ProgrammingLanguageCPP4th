/*
 * lexicographical_compare.cpp
 *
 *  Created on: 2016/12/02
 *      Author: sasaki
 */

#include <algorithm>
#include <iostream>
using namespace std;

template<typename In, typename In2>
bool my_lexicographical_compare(In first, In last, In2 first2, In2 last2)
{
	for (; first!=last && first2!=last2; ++first, ++first2) {
		if (*first < *first2)
			return true;
		if (*first2 < *first)
			return false;
	}

	return first==last && first2!=last2;
}

int main()
{
	string n1 {"10000"};
	string n2 {"999"};

	bool b1 = lexicographical_compare(n1.begin(), n1.end(), n2.begin(), n2.end());
	cout << "b1: " << b1 << endl;
	b1 = my_lexicographical_compare(n1.begin(), n1.end(), n2.begin(), n2.end());
	cout << "b1: " << b1 << endl;

	n1 = "Zebra";
	n2 = "Aardvark";

	bool b2 = lexicographical_compare(n1.begin(), n1.end(), n2.begin(), n2.end());
	cout << "b2: " << b2 << endl;
	b2 = my_lexicographical_compare(n1.begin(), n1.end(), n2.begin(), n2.end());
	cout << "b2: " << b2 << endl;
}
