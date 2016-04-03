/*
 * stream_iterator.cpp
 *
 *  Created on: 2016/04/03
 *      Author: sasaki
 */

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int test1()
{
	string from, to;
	cin >> from >> to;

	ifstream is {from};
	istream_iterator<string> ii {is};
	istream_iterator<string> eos {};

	ofstream os {to};
	ostream_iterator<string> oo {os, "\n"};

	vector<string> b {ii, eos};
	sort(b.begin(), b.end());

	unique_copy(b.begin(), b.end(), oo);

	return !is.eof() || !os;
}

int test2()
{
	string from, to;
	cin >> from >> to;

	ifstream is {from};
	ofstream os {to};

	set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}};
	copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});

	return !is.eof() || !os;
}

int main()
{
	cout << "calling test1()\n";
	test1();

	cout << "calling test2()\n";
	test2();
}
