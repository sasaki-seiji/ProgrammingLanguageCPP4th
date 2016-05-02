/*
 * name_in_namespace.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename U, typename V>
ostream& operator<<(ostream& os, const pair<U,V>& p)
{
	return os << '{' << p.first << ',' << p.second << '}';
}

void print_all(const map<string,int>& m, const string& label)
{
	cout << label << ":\n{\n";
	for_each(m.begin(), m.end(),
			[](const pair<string,int>& p) { cout << p << '\n'; }
	);
	cout << "}\n";
}

int main()
{
	map<string,int> m;

	for (int i = 0; i != 10; ++i)
		m["key#" + to_string(i)] = i;

	print_all(m, "print map");
}
