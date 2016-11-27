/*
 * construct_unordered_map.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

struct My_comparator {
	bool operator()(const string& a, const string& b) const { return b < a; }
};


void map_constructor()
{
	map<string,int,My_comparator> m {My_comparator{}};
	cout << "m.size(): " << m.size() << endl;
}

struct My_hasher {
	size_t operator()(const string& a) const { return hash<string>{}(a); }
};

void unordered_map_constructor()
{
	//unordered_map<string,int,My_hasher> um {My_hasher{}};
		// error: no match for call to '(const My_hasher) (const std::__cxx11::basic_string<char>&)'
	unordered_map<string,int,My_hasher> um {100,My_hasher{}};
	cout << "um.size(): " << um.size() << endl;
	cout << "um.bucket_count(): " << um.bucket_count() << endl;

	unordered_map<string,int> um2;
	cout << "um2.size(): " << um2.size() << endl;
	cout << "um2.bucket_count(): " << um2.bucket_count() << endl;

	vector<pair<string,int>> vs {{"abc",1}, {"xyz",2}, {"123",3} };
	unordered_map<string,int> um3 {vs.begin(),vs.end()};
	cout << "um3.size(): " << um3.size() << endl;
	cout << "um3.bucket_count(): " << um3.bucket_count() << endl;

	unordered_map<string,int> um4 {{{"abc",1}, {"xyz",2}, {"123",3}}, 1000};
	cout << "um4.size(): " << um4.size() << endl;
	cout << "um4.bucket_count(): " << um4.bucket_count() << endl;

	unordered_map<string,int> um5 {um3};
	cout << "um5.size(): " << um5.size() << endl;
	cout << "um5.bucket_count(): " << um5.bucket_count() << endl;
}

int main()
{
	map_constructor();
	unordered_map_constructor();
}
