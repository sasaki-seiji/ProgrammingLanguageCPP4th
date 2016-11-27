/*
 * test_map.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */


#include <map>
#include <string>
#include <iostream>
using namespace std;

struct Coordinate {
	string pos;
	Coordinate(const char* p) : pos{p} { }
};

ostream& operator<<(ostream& os, const pair<Coordinate,Coordinate>& v)
{
	return os << '(' << v.first.pos << ',' << v.second.pos << ')';
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K,V>& m)
{
	for (auto& x : m)
		os << x.first << '=' << x.second << ", ";
	return os;
}

void test_map_constructor()
{
	cout << "--- test_map_constructor() ---\n";

	map<string,pair<Coordinate,Coordinate>> locations
	{
		{"Copenhagen", {"55:40N","12:34E"}},
		{"Rome", {"41:54N","12:30E"}},
		{"New York", {"40:40N","73:56W"}}
	};
	cout << "locations: " << locations << endl;
}

void insert_seal(map<string,string>& dictionary)
{
	auto q = dictionary.find("seal");

	if (q==dictionary.end()) {
		cout << "entry not found\n";
		dictionary.insert(make_pair("seal", "eats fish"));
	}
	else
		cout << q->second << '\n';
}

void test_map_insert()
{
	cout << "--- test_map_insert() ---\n";

	map<string,string> dictionary;
	dictionary["sea"] = "large body of water";
	//cout << dictionary["seal"] << '\n';

	insert_seal(dictionary);
	insert_seal(dictionary);
}

void emplace_seal(map<string,string>& dictionary)
{
	auto q = dictionary.find("seal");

	if (q==dictionary.end()) {
		cout << "entry not found\n";
		dictionary.emplace("seal", "eats fish");
	}
	else
		cout << q->second << '\n';
}

void test_map_emplace()
{
	cout << "--- test_map_emplace() ---\n";

	map<string,string> dictionary;
	dictionary["sea"] = "large body of water";

	emplace_seal(dictionary);
	emplace_seal(dictionary);
}

void test_multimap_equal_range()
{
	cout << "--- test_multimap_equal_range() ---\n";

	multimap<string,int> mm {{"apple",2}, {"pear", 2}, {"apple", 7},
								{"orange",2}, {"apple",9}};
	const string k {"apple"};
	auto pp = mm.equal_range(k);
	if (pp.first==pp.second)
		cout << "no element with value '" << k << "'\n";
	else {
		cout << "elements with value '" << k << "':\n";
		for (auto p=pp.first; p!=pp.second; ++p)
			cout << p->second << ' ';
		cout << '\n';
	}
}
