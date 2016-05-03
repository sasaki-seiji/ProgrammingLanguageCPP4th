/*
 * mutable_lambda_expression.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void algo(vector<int>& v)
{
	int count = v.size();
	std::generate(v.begin(), v.end(),
			[count]()mutable{ return --count; }
	);
}

ostream& operator<<(ostream&os, const vector<int>& v)
{
	os << "[ ";
	for (auto x : v)
		os << x << ' ';
	os << "]\n";
	return os;
}

int main()
{
	vector<int> v(10, 3);
	cout << v;
	algo(v);
	cout << v;
}

