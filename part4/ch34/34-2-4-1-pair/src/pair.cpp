/*
 * pair.cpp
 *
 *  Created on: 2016/12/06
 *      Author: sasaki
 */


#include <utility>
#include <tuple>
#include <iostream>
using namespace std;

void f()
{
	pair<string,int> p {"Cambride",1209};
	cout << p.first;
	p.second += 800;
	cout << ':' << p.second << endl;;
}

struct Univ {
	Univ(const string& n, int r) : name{n}, rank{r} { }
	string name;
	int rank;
	string city = "unknown";
};

ostream& operator<<(ostream& os, const Univ& u)
{
	os << '{' << u.name << ',' << u.rank << ',' << u.city << '}';
	return os;
}

using Tup = tuple<string,int>;

ostream& operator<<(ostream& os, const Tup& t)
{
	os << '{' << get<0>(t) << ',' << get<1>(t) << '}';
	return os;
}

Tup t1 {"Columbia",11};
Tup t2 {"Cambridge",2};

pair<Tup,Tup> p1 {t1,t2};
pair<Univ,Univ> p2 {piecewise_construct,t1,t2};

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p)
{
	os << '(' << p.first << ',' << p.second << ')';
	return os;
}

int main()
{
	f();

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
}
