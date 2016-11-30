/*
 * fill.cpp
 *
 *  Created on: 2016/11/30
 *      Author: sasaki
 */


#include <algorithm>
#include <array>
#include <iterator>
#include <random>
#include <functional>
#include <iostream>
using namespace std;

// 40.7
class Rand_int {
public:
	Rand_int(int lo, int hi) :p{lo,hi} { }
	int operator()() const { return r(); }
private:
	uniform_int_distribution<>::param_type p;
	//auto r = bind(uniform_int_distribution<>{p},default_random_engine{});
	function<int()> r = bind(uniform_int_distribution<>{p},default_random_engine{});
};

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto& x : v)
		os << x << ',';
	return os;
}

int v1[900];
array<int,900> v2;
vector<int> v3;

void f()
{
	fill(begin(v1),end(v1),99);
	generate(begin(v2),end(v2),Rand_int{500,1500});
	generate_n(ostream_iterator<int>{cout,"\n"},200,Rand_int{0,100});
	fill_n(back_inserter(v3),20,99);
}

void g()
{
	vector<string> vs {"Breugel", "El Greco", "Delacroix", "Constable"};
	vector<string> vs2 {"Hals", "Goya", "Renoir", "Turner"};
	copy(vs.begin(), vs.end(), vs.begin());
	cout << "vs: " << vs << endl;
	uninitialized_copy(vs.begin(), vs.end(), vs2.begin()); // leak!!
	cout << "vs: " << vs << endl;
}

int main()
{
	f();

	cout << "v1: ";
	for (size_t i = 0; i!=900; ++i)
		cout << v1[i] << ',';
	cout << endl;

	cout << "v2: ";
	for (size_t i = 0; i!=900; ++i)
		cout << v2[i] << ',';
	cout << endl;

	cout << "v3: " << v3 << endl;

	g();
}
