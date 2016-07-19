/*
 * type_member.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename T>
class Tree {
	using value_type = T;
	enum Policy {rb, splay, treeps };
	class Node {
		Node* right;
		Node* left;
		value_type value;
	public:
		void f(Tree*);

		// 2016.07.19 add
		void add_node(value_type val);

		// 2016.07.18 add
		Node(value_type v, Node* r=nullptr, Node* l=nullptr)
		: right{r}, left{l}, value{v} { }
	};

	Node* top;

public:
	void g(Node*);
	void g() { g(top); }

	// 2016.07.19 add
	void add_node(value_type val);

	// 2016.07.18 add
	Tree() : top{nullptr} { }
};

template<typename T>
void Tree<T>::Node::f(Tree* p)
{
	//top = right;
		// invalid use of non-static data member 'Tree<int>::top'
	p->top = right;
	value_type v = left->value;

	cout << "in Tree<T>::Node::f(Tree*) - v: " << v << '\n';
}

template<typename T>
void Tree<T>::g(Node* p)
{
	//value_type val = right->value;
		//  'right' was not declared in this scope
	//value_type v = p->right->value;
		// 'Tree<int>::value_type Tree<int>::Node::value' is private
	p->f(this);
}

// 2016.07.19 add
template<typename T>
void Tree<T>::add_node(value_type val)
{
	if (top) {
		top->add_node(val);
	}
	else {
		top = new Node{val} ;
	}
}

// 2016.07.19 add
template<typename T>
void Tree<T>::Node::add_node(value_type val)
{
	if (val < value) {
		if (left)
			left->add_node(val);
		else
			left = new Node{val};
	}
	else {
		if (right)
			right->add_node(val);
		else
			right = new Node{val};
	}
}


// add main
int main()
{
	Tree<int> tree;

	tree.add_node(20);
	tree.add_node(10);
	tree.add_node(30);

	tree.g();
}
