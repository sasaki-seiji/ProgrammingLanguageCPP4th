/*
 * initializer_list_constructor.cpp
 *
 *  Created on: 2016/07/26
 *      Author: sasaki
 */

#include <vector>
#include <list>
#include <string>
#include <map>
#include <iostream>
#include <initializer_list>
using namespace std;

vector<double> v = { 1, 2, 3.456, 99.99 };

list<pair<string,string>> languages = {
	{"Nygaard", "Simula"}, {"Richards", "BCPL"}, {"Ritchie", "C"}
};

map<vector<string>, vector<int>> years = {
	{ {"Maurice", "Vincent", "Wilkes"}, {1913, 1945, 1951, 1967, 2000} },
	{ {"Martin", "Richards"}, {1982, 2003, 2007} },
	{ {"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004} }
};


void f(initializer_list<int>);

void g()
{
	f({1,2});
	f({23,345,4567,56789});
	f({});
	//f{1,2};
		// error: expected ';' before '{' token

	//years.insert({{"Bjane", "Stroustrup"}, {1950, 1975, 1985}});
		// Invalid arguments '
	//cout << years << endl;
}


// utilities

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[";
	for (auto& x : v)
		os << ' ' << x << ',';
	os << "]";
	return os;
}

template<typename U, typename V>
ostream& operator<<(ostream& os, const pair<U, V>& p)
{
	os << p.first << ':' << p.second;
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, const list<T>& v)
{
	os << "(";
	for (auto& x : v)
		os << ' ' << x << ',';
	os << ")";
	return os;
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K,V>& m)
{
	os << "{";
	for (auto& x : m)
		os << ' ' << x << ',';
	os << "}";
	return os;
}


// add undef func

void f(initializer_list<int> il)
{
	cout << "f({";
	for (auto x : il)
		cout << x << ',';
	cout << "})\n";
}


// add main

int main()
{
	cout << v << endl;
	cout << languages << endl;
	cout << years << endl;
	g();
}
