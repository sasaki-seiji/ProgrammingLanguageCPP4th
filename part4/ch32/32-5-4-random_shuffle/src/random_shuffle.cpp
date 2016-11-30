/*
 * random_shuffle.cpp
 *
 *  Created on: 2016/11/30
 *      Author: sasaki
 */


#include <algorithm>
#include <deque>
#include <cstdlib>
#include <iostream>
using namespace std;

struct Card {
	char mark;
	int num;
};

ostream& operator<<(ostream& os, const Card& c)
{
	return os << '(' << c.mark << ',' << c.num << ')';
}

template<typename T>
ostream& operator<<(ostream& os, const deque<T>& dq)
{
	for (auto& x : dq)
		os << x << ',';
	return os;
}

struct My_rand {
	size_t operator()(size_t n) { return rand() % n; }
};

void f(deque<Card>& dc, My_rand& r)
{
	random_shuffle(dc.begin(), dc.end(), r);
}

int main()
{
	deque<Card> dc {
		{'s',1}, {'s',2}, {'s',3}, {'s',4}, {'s',5}, {'s',6}, {'s',7},
		{'s',8}, {'s',9}, {'s',10}, {'s',11}, {'s',12}, {'s',13},
		{'h',1}, {'h',2}, {'h',3}, {'h',4}, {'h',5}, {'h',6}, {'h',7},
		{'h',8}, {'h',9}, {'h',10}, {'h',11}, {'h',12}, {'h',13},
		{'c',1}, {'c',2}, {'c',3}, {'c',4}, {'c',5}, {'c',6}, {'c',7},
		{'c',8}, {'c',9}, {'c',10}, {'c',11}, {'c',12}, {'c',13},
		{'d',1}, {'d',2}, {'d',3}, {'d',4}, {'d',5}, {'d',6}, {'d',7},
		{'d',8}, {'d',9}, {'d',10}, {'d',11}, {'d',12}, {'d',13},
		{'j',0}
	};

	My_rand r{};
	deque<Card> dc1{dc};
	f(dc1, r);
	cout << "dc1: " << dc1 << endl;

	deque<Card> dc2{dc};
	random_shuffle(dc2.begin(),dc2.end());
	cout << "dc2: " << dc2 << endl;
}
