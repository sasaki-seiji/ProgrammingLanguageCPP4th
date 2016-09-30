/*
 * user.cpp
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */


#include "sortedtree.h"
#include <vector>
#include <iostream>
using namespace std;

using My_node = Node<double>;

void user(const vector<double>& v)
{
	My_node root{1.5};

	for (auto x : v)
		root.insert(x);

	root.print_tree(cout);
}

// add main

int main()
{
	vector<double> v {0.001, 0.01, 0.1, 1.0, 10.0, 100.0, 1000.0};
	user(v);
}
