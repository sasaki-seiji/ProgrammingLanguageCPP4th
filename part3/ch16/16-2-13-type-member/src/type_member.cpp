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

		// 2016.07.18 add
		Node(value_type v, Node* r=nullptr, Node* l=nullptr)
		: right{r}, left{l}, value{v} { }
	};

	Node* top;

public:
	void g(Node*);

	// 2016.07.18 add
	Tree();
};

template<typename T>
Tree<T>::Tree()
{
	top = new Node(T{}, new Node(T{}), new Node(T{}));
	g(top);
}

template<typename T>
void Tree<T>::Node::f(Tree* p)
{
	//top = right;
		// error: invalid use of non-static data member 'Tree<int>::top'
	p->top = right;
	value_type v = left->value;

	cout << "in Tree<T>::Node::f(Tree*) - v: " << v << '\n';
}

template<typename T>
void Tree<T>::g(Node* p)
{
	//value_type val = right->value;
		//  error: request for member ‘value’ in ‘std::right->’, which is of non-class type ‘std::ios_base&(std::ios_base&)’
	//value_type v = p->right->value;
		// error: 'Tree<int>::value_type Tree<int>::Node::value' is private
	p->f(this);
}


// add main
int main()
{
	Tree<int> tree;
	return 0;
}
