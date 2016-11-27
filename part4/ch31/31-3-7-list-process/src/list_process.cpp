/*
 * list_process.cpp
 *
 *  Created on: 2016/11/25
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
#include <list>
#include <utility>
using namespace std;

void test_list_process()
{
	vector<int> v {4,3,5,1};
	auto p = v.begin()+2;
	cout << "*p: " << *p << endl;

	v.push_back(6);	// p is invalidated
	cout << "*p: " << *p << endl;

	p = v.begin()+2;
	auto p2 = v.begin()+4;
	cout << "*p2: " << *p2 << endl;

	v.erase(v.begin()+3);	// p2 is invalidated
	cout << "*p: " << *p << endl;
	cout << "*p2: " << *p2 << endl;
}

void user(list<pair<string,double>>& lst)
{
	auto p = lst.begin();
	while (p!=lst.end() && p->first!="Denmark")
		++p;
	p=lst.emplace(p,"England",7.5);
	p=lst.insert(p,make_pair("France", 9.8));
	p=lst.insert(p,pair<string,double>{"Greece",3.14});
}

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const list<pair<T1,T2>>& lst)
{
	for (auto& x : lst)
		os << '(' << x.first << ',' << x.second << ") ";
	return os;
}

int main()
{
	test_list_process();
	list<pair<string,double>> lst;
	lst.push_back({"USA", 10.4});
	lst.push_back({"Japan", 8.5});
	lst.push_back({"Denmark", 6.4});
	user(lst);
	cout << "lst: " << lst << endl;
}
