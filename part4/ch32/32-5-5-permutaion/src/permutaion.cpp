/*
 * permutaion.cpp
 *
 *  Created on: 2016/11/30
 *      Author: sasaki
 */


#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	vector<char> v {'a','b','c'};
#if 0
	while(next_permutation(v.begin(),v.end()))
		cout << v[0] << v[1] << v[2] << ' ';
#else
	do {
		cout << v[0] << v[1] << v[2] << ' ';
	} while(next_permutation(v.begin(),v.end()));
#endif
	cout << '\n';
}
