/*
 * type_member.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

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
	};
	Node* top;
public:
	void g(Node*);
};

template<typename T>
void Tree<T>::Node::f(Tree* p)
{
	top = right;
	p->top = right;
	value_type v = left->value;
}

template<typename T>
void Tree<T>::g(Node* p)
{
	//value_type val = right->value;
		//  'right' was not declared in this scope
	value_type v = p->right->value;
	p->f(this);
}


// add main
int main()
{
	Tree<int> tree;
}


