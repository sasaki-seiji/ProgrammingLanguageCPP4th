/*
 * load_factor.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <unordered_set>
#include <iostream>
using namespace std;

struct Record {
	string name;
	int val;
};

namespace std {

	template<>
	struct hash<Record> {
		size_t operator()(const Record& r) const
		{
			return hash<string>{}(r.name)^hash<int>{}(r.val);
		}
	};

	template<>
	struct equal_to<Record> {
		bool operator()(const Record& r, const Record& r2) const
		{
			return r.name==r2.name && r.val==r2.val;
		}
	};
}

static void display_metrics(const unordered_set<Record>& people)
{
	cout << "size: " << people.size() << endl;
	cout << "bucket_count: " << people.bucket_count() << endl;
	cout << "max_bucket_count: " << people.max_bucket_count() << endl;
	cout << "load_factor: " << people.load_factor() << endl;
	cout << "max_load_factor: " << people.max_load_factor() << endl;
	for (size_t i = 0; i < people.bucket_count(); ++i)
		if (people.bucket_size(i) != 0 )
			cout << "    bucket_size(" << i << "): " << people.bucket_size(i) << endl;
}

void load_factor()
{
	unordered_set<Record> people {
		{"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12}
	};
	cout << "--- initial metrics ---\n";
	display_metrics(people);

	constexpr int expected = 1000000;
	people.max_load_factor(0.7);
	people.reserve(expected);
	cout << "--- metrics after reserve ---\n";
	display_metrics(people);
}

int main()
{
	load_factor();
}

