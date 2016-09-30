/*
 * user.cpp
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */


#include "binarytree.h"
#include <vector>
#include <iostream>
using namespace std;

using My_node = Node<double>;

void user(const vector<double>& v)
{
	My_node root{1.5};
	int i = 0 ;

	for (auto x : v) {
		auto p = new My_node{x};
		if (i++%2)
			root.add_left(p);
		else
			root.add_right(p);
	}

	root.print_tree(cout);
}

// add main

int main()
{
	vector<double> v {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	user(v);
}
