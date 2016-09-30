/*
 * sortedtree.h
 *
 *  Created on: 2016/10/01
 *      Author: sasaki
 */

#ifndef SORTEDTREE_H_
#define SORTEDTREE_H_

#include <ostream>

struct Balancing_info { };

template<typename N>
struct Node_base {
	N* left_child;
	N* right_child;
	Balancing_info bal;

	Node_base(): left_child{nullptr}, right_child{nullptr} { }

	void add_left(N& n)
	{
		if (left_child==nullptr)
			left_child = &n;
		else if (n < *left_child)
			left_child->add_left(n);
		else
			left_child->add_right(n);
	}

	void add_right(N& n)
	{
		if (right_child==nullptr)
			right_child = &n;
		else if (n < *right_child)
			right_child->add_left(n);
		else
			right_child->add_right(n);
	}
};

template<typename Val>
struct Node : Node_base<Node<Val>> {
	Val v;
	Node(Val vv) : v{vv} { }

	void insert(Val x)
	{
		Node* p = new Node{x};
		if (x < v)
			this->add_left(*p);
		else
			this->add_right(*p);
	}

	void print_tree(std::ostream& os)
	{
		if (this->left_child) this->left_child->print_tree(os);
		os << ' ' << v;
		if (this->right_child) this->right_child->print_tree(os);
	}
};

template<typename Val>
bool operator<(const Node<Val>& a, const Node<Val>& b)
{
	return a.v < b.v;
}


#endif /* SORTEDTREE_H_ */
