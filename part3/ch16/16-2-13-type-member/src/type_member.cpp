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
public: // 2016.07.18 change to public from private
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

private:
	Node* top;

public:
	void g(Node*);

	// 2016.07.18 add
	Tree(Node* t = nullptr) : top{t} { }
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


// add main
int main()
{
	Tree<int>::Node node_r {10};
	Tree<int>::Node node_l {20};
	Tree<int>::Node node_top {30, &node_r, &node_l};
	Tree<int> tree {&node_top};

	tree.g(&node_top);
}


