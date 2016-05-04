/*
 * transform_to_lambda_expression.cpp
 *
 *  Created on: 2016/05/02
 *      Author: sasaki
 */

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

void print_modulo3(const vector<int>& v, ostream& os, int m)
{
	class Modulo_print {
		ostream& os;
		int m;
	public:
		Modulo_print(ostream& s, int mm) :os(s), m(mm) {}
		void operator()(int x) const
			{ if (x % m == 0) os << x << '\n'; }
	};

	for_each(begin(v), end(v), Modulo_print{os,m});
}

void print_modulo4(const vector<int>& v, ostream& os, int m)
{
	auto Modulo_print = [&os,m](int x){ if (x%m==0) os << x << '\n'; };

	for_each(begin(v), end(v), Modulo_print);
}

void print_modulo5(const vector<int>& v, ostream& os, int m)
{
	for (auto x : v)
		if (x % m == 0)
			os << x << '\n';
}

// 2016.05.02 add:
// no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'std::pair<const std::__cxx11::basic_string<char>, int>')
ostream& operator<<(ostream& os, const pair<string, int>& p)
{
	os << '(' << p.first << ',' << p.second << ')' ;
	return os;
}

template<typename C, typename Fct>
void print_modulo6(C& v, ostream& os, int m, Fct f)
{
	for (auto x : v)
		if (f(x) % m == 0)
			os << x << '\n';
}

void test(vector<int>& v, map<string, int>& m)
{
	print_modulo6(v, cout, 99, [](int x) { return x; });
	print_modulo6(m, cout, 77,
			[](const pair<const string, int>& x){ return x.second; });

}

int main()
{
	vector<int> v;
	for (int i = 0; i < 100; ++i)
		v.push_back(i);

	print_modulo3(v, cout, 17);
	print_modulo4(v, cout, 19);
	print_modulo4(v, cout, 23);

	v.clear();
	map<string,int> m;
	for (int i = 0; i < 500; ++i) {
		v.push_back(i);
		m["key"+to_string(i)] = i;
	}
	test(v, m);

}
