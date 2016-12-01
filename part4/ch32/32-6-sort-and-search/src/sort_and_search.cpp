/*
 * sort_and_search.cpp
 *
 *  Created on: 2016/12/01
 *      Author: sasaki
 */

#include "concept.h"
using namespace Estd;

#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <random>
#include <functional>
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const list<T>& lst)
{
	for (auto& x : lst)
		os << x << ", ";
	return os;
}

template<typename T, typename Cmp = less<T>>
void sort(vector<T>& v, Cmp cmp = Cmp{})
{
	sort(v.begin(), v.end(), cmp);
}

template<typename Src, typename Dst>
void copy(Src& s, Dst& d)
{
	copy(s.begin(), s.end(), d.begin());
}

// sort for list
template<typename List>
void sort_list(List& lst)
{
	vector<Value_type<List>> v {lst.begin(), lst.end()};
	sort(v);
	copy(v, lst);
}

struct Book {
	string title;
	int n_sold;
	int copies_sold() const { return n_sold; }
};

ostream& operator<<(ostream& os, const Book& book)
{
	return os << "title=" << book.title << ", copies_sold=" << book.n_sold;
}

// std::partial_sort_copy
void f(const vector<Book>& sales)
{
	vector<Book> bestsellers(10);
	partial_sort_copy(sales.begin(), sales.end(),
		bestsellers.begin(), bestsellers.end(),
		[](const Book& b1, const Book& b2)
			{ return b1.copies_sold() > b2.copies_sold(); });
	copy(bestsellers.begin(), bestsellers.end(), ostream_iterator<Book>(cout, "\n"));
}

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

// std::nth_element
void test_nth_element()
{
	vector<int> v;
	Rand_int gen {1,1000};
	for (int i=0; i<1000; ++i)
		v.push_back(gen());

	constexpr int n = 30;
	nth_element(v.begin(), v.begin()+n, v.end());

	cout << "nth: " << v[n] << endl;
	for (int i=0; i<n; ++i)
		cout << v[i] << ' ';
	cout << endl;
}

// std::partial_sort
void test_partial_sort()
{
	vector<int> v;
	Rand_int gen {1,1000};
	for (int i=0; i<1000; ++i)
		v.push_back(gen());

	constexpr int n = 30;
	partial_sort(v.begin(), v.begin()+n, v.end());

	cout << "nth: " << v[n] << endl;
	for (int i=0; i<n; ++i)
		cout << v[i] << ' ';
	cout << endl;
}

vector<string> vs = {"Helsinki", "Copenhagen", "Oslo", "Stockholm"};
vector<const char*> vcs = {"Helsinki", "Copenhagen", "Oslo", "Stockholm"};

// sort vector<const char*>
void use()
{
	sort(vs);
	sort(vcs);

	for (auto& x : vs)
		cout << x << ' ';
	cout << endl;
	for (auto& x : vcs)
		cout << x << ' ';
	cout << endl;

	sort(vcs, [](const char* p, const char* q){ return strcmp(p,q) < 0; });
	for (auto& x : vcs)
		cout << x << ' ';
	cout << endl;
}

int main()
{
	list<int> lst {4,2,7,3,9,5,1,4,2,0,2};
	sort_list(lst);
	cout << "lst: " << lst << endl;

	vector<Book> vb;
	for (size_t i = 0; i < 100; ++i) {
		Book book = {string("book#") + to_string(i), rand()%100};
		vb.push_back(book);
	}
	f(vb);

	test_nth_element();
	test_partial_sort();

	use();
}
