/*
 * list.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */


#include <list>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const list<T>& lst)
{
	for (auto x : lst)
		os << x << ' ';
	return os;
}

void use()
{
	list<int> lst {2,3,2,3,5};
	cout << "originally lst: " << lst << endl;

	lst.remove(3);
	cout << "after remove(3), lst :" << lst << endl;

	lst.unique();
	cout << "after unique(), lst: " << lst << endl;
	cout << lst.size() << '\n';
}

void test_splice()
{
	list<int> lst1 {1,2,3};
	cout << "originally lst1: " << lst1 << endl;

	list<int> lst2 {5,6,7};
	cout << "originally lst2: " << lst2 << endl;

	auto p = lst1.begin();
	++p;
	auto q = lst2.begin();
	++q;
	cout << "before splice(), *p: " << *p << ", *q: " << *q << endl;

	lst1.splice(p,lst2);
	cout << "after splice(), lst1: " << lst1 << ", lst2: " << lst2 << endl;
	cout << "after splice(), *p: " << *p << ", *q: " << *q << endl;
}

int main()
{
	use();
	test_splice();
}
