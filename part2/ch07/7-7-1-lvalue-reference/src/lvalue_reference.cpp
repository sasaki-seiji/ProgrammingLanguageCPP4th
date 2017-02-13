/*
 * lvalue_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

void f()
{
	cout << "-- f() --\n";

	int var = 1;
	int& r {var};
	int x = r;

	r = 2;

	cout << "var = " << var << '\n';
	cout << "r = " << r << '\n';
	cout << "x = " << x << '\n';
}

int var = 1;
int& r1 {var};
//int& r2;
	// error: 'r2' declared as reference but not initialized
extern int& r3;	// defined anywhere

void g()
{
	cout << "-- g() --\n";

	int var = 0;
	int& rr {var};
	++rr;
	int* pp = &rr;

	cout << "var = " << var << '\n';
	cout << "rr = " << rr << '\n';
	cout << "pp = " << pp << ", &var = " << &var << '\n';
}

//double& dr = 1;
	// error: invalid initialization of non-const reference of type 'double&' from an rvalue of type 'double'
const double& cdr {1};

void increment(int& aa)
{
	++aa;
}
void f2()
{
	cout << "-- f2() --\n";

	int x = 1;
	increment(x);
	cout << "x = " << x << '\n';
}

int next(int p) { return p+1; }
void g2()
{
	cout << "-- g2() --\n";

	int x = 1;
	increment(x);
	x = next(x);
	cout << "x = " << x << '\n';
}

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
	cout << "::var = " << ::var << '\n';
	cout << "::r1 = " << ::r1 << '\n';
	cout << "::r3 = " << ::r3 << '\n';

	f();
	g();
	f2();
	g2();

	cout << "-- enter words:\n";
	Map<string,int> buf;
	for (string s; cin >> s; ) ++buf[s];
	for (const auto& x : buf)
		cout << x.first << ": " << x.second << '\n';
}

int temp = 3;
int& r3 {temp};
