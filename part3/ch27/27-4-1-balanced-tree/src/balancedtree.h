/*
 * balancedtree.h
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */

#ifndef BALANCEDTREE_H_
#define BALANCEDTREE_H_


#include <ostream>

template<typename N, typename Balance>
struct Node_base : Balance {
	N* left_child;
	N* right_child;

	Node_base(): left_child{nullptr}, right_child{nullptr} { }

	void add_left(N& n)
	{
		if (left_child==nullptr)
			left_child = &n;
		else if (this->compare(n, *left_child))
			left_child->add_left(n);
		else
			left_child->add_right(n);
	}

	void add_right(N& n)
	{
		if (right_child==nullptr)
			right_child = &n;
		else if (this->compare(n, *right_child))
			right_child->add_left(n);
		else
			right_child->add_right(n);
	}
};

template<typename Val, typename Balance>
struct Search_node : Node_base<Search_node<Val,Balance>, Balance> {
	Val v;
	Search_node(Val vv) : v{vv} { }

	void insert(Search_node& n)
	{
		if (this->compare(n,*this))
			this->add_left(n);
		else
			this->add_right(n);
	}

	void print_tree(std::ostream& os)
	{
		if (this->left_child) this->left_child->print_tree(os);
		os << ' ' << v;
		if (this->right_child) this->right_child->print_tree(os);
	}
};


#endif /* BALANCEDTREE_H_ */
