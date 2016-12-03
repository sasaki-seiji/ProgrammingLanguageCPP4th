/*
 * move_iterator.cpp
 *
 *  Created on: 2016/12/03
 *      Author: sasaki
 */


#include <iterator>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> read_strings(istream& is)
{
	vector<string> vs;
	string word;
	while (cin >> word) {
		vs.push_back(word);
	}
	return vs;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ',';
	return os;
}

int main()
{
	auto vs = read_strings(cin);

	vector<string> vs2;
	copy(vs.begin(), vs.end(), back_inserter(vs2));
	cout << "vs: " << vs << endl;
	cout << "vs2: " << vs2 << endl;

	vector<string> vs3;
	copy(make_move_iterator(vs2.begin()), make_move_iterator(vs2.end()),
			back_inserter(vs3));
	cout << "vs2: " << vs2 << endl;
	cout << "vs3: " << vs3 << endl;
}


