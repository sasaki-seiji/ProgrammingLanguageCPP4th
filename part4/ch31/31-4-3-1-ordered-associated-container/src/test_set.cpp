/*
 * test_set.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */


#include <set>
#include <string>
#include <iostream>
using namespace std;

struct Record {
	string label;
	int value;
};

bool operator<(const Record& a, const Record& b)
{
	return a.label < b.label;
}

set<Record> mr {{"duck",10}, {"pork",12}};

void read_test()
{
	cout << "--- read_test() ---\n";

	for (auto& r : mr) {
		cout << '{' << r.label << ':' << r.value << '}';
	}
	cout << '\n';
}

void modify_test()
{
#if 0
	for (auto& r : mr)
		++r.value;
			// error: increment of member 'Record::value' in read-only object
#endif
}
