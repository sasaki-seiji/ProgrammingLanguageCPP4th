/*
 * terminate_loop.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void f(vector<string>&v, string terminate)
{
	string s;
	while (cin>>s) {
		if (s == terminate) break;
		v.push_back(s);
	}
}

void print(const vector<string>& v)
{
	for (auto& x : v)
		cout << x << '\n';
}

bool prime(const string&s)
{
	return s == "prime";
}

string find_prime(vector<string>& v)
{
	//for (int i = 0; i != v.size(); ++i) {
	for (size_t i = 0; i != v.size(); ++i) {
		// comparison between signed and unsigned integer expressions [-Wsign-compare]

		if (!prime(v[i]))
			continue;
		return v[i];
	}
	return "not found";
}

string find_prime2(vector<string>& v)
{
	for (size_t i = 0; i != v.size(); ++i) {
		if (prime(v[i]))
			return v[i];
	}
	return "not found";
}

int main()
{
	vector<string> v;
	string end {"end"};

	f(v, end);
	print(v);

	string match = find_prime(v);
	cout << "find_prime(v) returns \"" << match << "\"\n";
	cout << "find_prime2(v) returns \"" << find_prime2(v) << "\"\n";
}
