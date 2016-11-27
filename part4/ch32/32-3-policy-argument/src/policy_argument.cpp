/*
 * policy_argument.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


bool pred(int);

using Predicate = bool(*)(int);

void f(vector<Predicate>& v1, vector<int>& v2)
{
	auto p1 = find(v1.begin(),v1.end(),pred);
	auto p2 = find_if(v2.begin(),v2.end(),pred);

	if (p1!=v1.end()) {
		cout << "found pred\n";
	}
	if (p2!=v2.end()) {
		cout << "found pred(x): " << *p2 << endl;
	}
}

int n_even(vector<int>& v)
{
	return count_if(v.begin(),v.end(),[](int& x){ ++x; return x&1; });
}

bool pred(int x)
{
	return x % 7 == 0;
}

bool is_even(int x)
{
	return x % 2 == 0;
}

bool is_multiple_of_3(int x)
{
	return x % 4 == 0;
}

bool is_multiple_of_5(int x)
{
	return x % 5 == 0;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

int main()
{
	vector<int> vi { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<Predicate> vp { is_even, is_multiple_of_3, is_multiple_of_5, pred };

	f(vp,vi);

	cout << "vi: " << vi << endl;
	int n = n_even(vi);
	cout << "n_even(vi) returns: " << n << endl;
	cout << "after n_even() call, vi: " << vi << endl;
}
