/*
 * transform_to_lambda_expression.cpp
 *
 *  Created on: 2016/05/02
 *      Author: sasaki
 */

#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include <iostream>
using namespace std;

void print_modulo3(const vector<int>& v, ostream& os, int m)
{
	cout << "-- print_modulo3(const vector<int>&,ostream&, int:" << m << ") --\n";

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
	cout << "-- printf_modulo4(const vector<int>&,ostream&,int:" << m << ") --\n";

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
	cout << "-- print_modulo6(C&:" << typeid(v).name() << ",ostream&,int:" << m << ",Fct) --\n";

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

class Tree {
	int v;
	Tree *l, *r;
public:
	Tree(int vv, Tree* ll=nullptr, Tree* rr=nullptr)
		: v{vv}, l{ll}, r{rr} { }
	int value() const { return v; }
	Tree* left() const { return l; }
	Tree* right() const { return r; }
};

template<typename Fct>
void depth_first_recursive(const Tree* tree, Fct f)
{
	if (Tree* l = tree->left()) depth_first_recursive(l, f);
	f(tree->value());
	if (Tree* r = tree->right()) depth_first_recursive(r, f);
}

template<typename Fct>
void depth_first(const Tree& tree, Fct f)
{
	cout << "-- depth_first(const Tree&, Fct) --\n";

	depth_first_recursive(&tree, f);
}

template<typename Fct>
void breadth_first(const Tree& tree, Fct f)
{
	cout << "-- breadth_first(const Tree&, Fct) --\n";

	queue<const Tree*> fifo;
	fifo.push(&tree);

	while (!fifo.empty()) {
		const Tree *p = fifo.front();
		fifo.pop();

		f(p->value());
		if (Tree* l = p->left()) fifo.push(l);
		if (Tree* r = p->right()) fifo.push(r);
	}
}

template<typename K, typename V, typename Fct>
void every_second_element(const map<K,V>& m, Fct f)
{
	cout << "-- every_second_element(const map&, Fct) --\n";
	for (const auto& x : m)
		f(x.second);
}

void test_scanner(ostream& os, int m)
{
	Tree *t11 = new Tree{11}, *t12 = new Tree{12}, *t21 = new Tree{21};
	Tree *t10 = new Tree{10,t11, t12}, *t20 = new Tree{20, t21};
	Tree *root = new Tree{100, t10, t20};

	depth_first(*root, [&os,m](int x) { if (x%m==0) os << x << '\n'; });
	breadth_first(*root, [&os,m](int x){ if (x%m==0) os << x << '\n'; });

	map<string,int> digits {
		{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
		{"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"tem", 10}
	};
	every_second_element(digits, [&os,m](int x){ if (x%m==0) os << x << '\n'; });
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
	test_scanner(cout, 2);
}
