/*
 * unordered_map.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */


#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;


unordered_map<string,int> score1 {
	{"andy", 7}, {"al", 9}, {"bill", -3}, {"barbara", 12}
};

map<string,int> score2 {
	{"andy", 7}, {"al", 9}, {"bill", -3}, {"barbara", 12}
};

template<typename X, typename Y>
ostream& operator<<(ostream& os, const pair<X,Y>& p)
{
	return os << '{' << p.first << ',' << p.second << '}';
}

void user()
{
	cout << "unordered: ";
	for (const auto& x : score1)
		cout << x << ", ";
	cout << "\nordered: ";
	for (const auto& x : score2)
		cout << x << ", ";
	cout << '\n';
}

int main()
{
	user();
}
