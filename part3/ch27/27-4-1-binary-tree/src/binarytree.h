/*
 * binarytree.h
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <cstdlib>
#include <ostream>

template<typename N>
struct Node_base {
	N* left_child;
	N* right_child;

	Node_base(): left_child{nullptr}, right_child{nullptr} { }

	void add_left(N* p)
	{
		if (left_child==nullptr)
			left_child = p;
		else {
			int r = std::rand();
			if (r%2==0)
				left_child->add_left(p);
			else
				left_child->add_right(p);
		}
	}

	void add_right(N* p)
	{
		if (right_child==nullptr)
			right_child = p;
		else {
			int r = std::rand();
			if (r%2==0)
				right_child->add_left(p);
			else
				right_child->add_right(p);
		}
	}
};

template<typename Val>
struct Node : Node_base<Node<Val>> {
	Val v;
	Node(Val vv) : v{vv} { }

	void print_tree(std::ostream& os)
	{
		if (this->left_child) this->left_child->print_tree(os);
		os << ' ' << v;
		if (this->right_child) this->right_child->print_tree(os);
	}
};

#endif /* BINARYTREE_H_ */
