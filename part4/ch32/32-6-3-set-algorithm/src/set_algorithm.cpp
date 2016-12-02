/*
 * set_algorithm.cpp
 *
 *  Created on: 2016/12/02
 *      Author: sasaki
 */


#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s1 = "qwertyasdfgzxcvb";
	string s2 = "poiuyasdfg/.,mnb";
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	string s3(s1.size()+s2.size(), '*');
	cout << s3 << '\n';
	auto up = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
	cout << s3 << '\n';
	for (auto p = s3.begin(); p!=up; ++p) cout << *p;
	cout << '\n';

	s3.assign(s1.size()+s2.size(), '+');
	up = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
	cout << s3 << '\n';
	for (auto p = s3.begin(); p!=up; ++p) cout << *p;
	cout << '\n';
}
