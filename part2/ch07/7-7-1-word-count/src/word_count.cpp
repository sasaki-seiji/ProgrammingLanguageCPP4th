/*
 * word_count.cpp
 *
 *  Created on: 2017/02/13
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;


template<typename K, typename V>
class Map {
public:
	V& operator[](const K& k);
	pair<K,V>* begin() { return &elem[0]; }
	pair<K,V>* end() { return &elem[0]+elem.size(); }
private:
	vector<pair<K,V>> elem;
};

template<typename K, typename V>
V& Map<K,V>::operator[](const K& k)
{
	for (auto& x : elem)
		if (k == x.first)
			return x.second;

	elem.push_back({k,V{ }});
	return elem.back().second;
}


int main()
{
	Map<string,int> buf;
	for (string s; cin >> s; ) ++buf[s];
	for (const auto& x : buf)
		cout << x.first << ": " << x.second << '\n';
}

