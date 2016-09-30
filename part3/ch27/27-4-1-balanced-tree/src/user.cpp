/*
 * user.cpp
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */


#include "balancedtree.h"
#include <vector>
#include <iostream>
using namespace std;

struct Red_black_balance {
	template<typename Val, typename Balance>
	bool compare(const Search_node<Val, Balance>& a, const Search_node<Val, Balance>& b)
	{
		return a.v < b.v;
	}
};

template<typename T>
using Rb_node = Search_node<T,Red_black_balance>;

using My_node = Rb_node<double>;
My_node my_root {3.5};

void user(const vector<double>& v)
{
	for (auto x : v)
		my_root.insert(*new My_node{x});

	my_root.print_tree(cout);
}

// add main

int main()
{
	vector<double> v {0.001, 0.01, 0.1, 1.0, 10.0, 100.0, 1000.0};
	user(v);
}
