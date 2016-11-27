/*
 * sequence.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include "concept.h"
using namespace Estd;

#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::out_of_range;
using std::ostream;
using std::cout;
using std::endl;

void user(vector<int>& v1, vector<int>& v2)
{
	std::copy(v1.begin(),v1.end(),v2.begin());
	//sort(v1.begin(),v2.end()); // crash
	std::sort(v1.begin(),v1.end());
}

template<typename Cont>
void sort(Cont& c)
{
	static_assert(Range<Cont>(), "sort(): Cont argument not a range");
	static_assert(Sortable<Iterator<Cont>>(), "sort(): Cont argument not Sortable");

	std::sort(begin(c),end(c));
}

template<typename Cont1, typename Cont2>
void copy(const Cont1& source, Cont2& target)
{
	static_assert(Range<Cont1>(), "copy(): Cont1 argument not a range");
	static_assert(Range<Cont2>(), "copy(): Cont2 argument not a range");
	if (target.size()<source.size()) throw out_of_range{"copy target too small"};

	std::copy(source.begin(),source.end(),target.begin());
}

void user2(vector<int>& v1, vector<int>& v2)
{
	copy(v1,v2);
	sort(v1);
}

template<typename Cont, typename Pred>
vector<Value_type<Cont>*>
find_all(Cont& c, Pred p)
{
	static_assert(Range<Cont>(), "find_all(): Cont argument not a range");
	//static_assert(Predicate<Pred>(), "find_all(): Pred argument not a Predicate");
	static_assert(Predicate<Pred, Value_type<Cont>>(),
							"find_all(): Pred argument not a Predicate");

	vector<Value_type<Cont>*> res;
	for (auto& x : c)
		if (p(x)) res.push_back(&x);
	return res;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

bool is_even(int x) { return x % 2 == 0; }

int main()
{
	vector<int> v1 {9,8,7,6,5,4,3,2,1,0};
	vector<int> v2 {0,1,2,3,4,5,6,7,8,9};

	user(v1,v2);
	cout << "v1: " << v1 << endl;
	cout << "v2: " << v2 << endl;

	vector<int> v3 {9,8,7,6,5,4,3,2,1,0};
	vector<int> v4 {0,1,2,3,4,5,6,7,8,9};

	user2(v3,v4);
	cout << "v3: " << v3 << endl;
	cout << "v4: " << v4 << endl;

	vector<int> vi {9,8,7,6,5,4,3,2,1,0};
	cout << "vi: " << vi << endl;
	vector<int*> vpe = find_all(vi, is_even);
	for (auto p : vpe)
		cout << *p << ", ";
	cout << endl;
}
