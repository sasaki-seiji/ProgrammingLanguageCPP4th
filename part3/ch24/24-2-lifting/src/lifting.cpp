/*
 * lifting.cpp
 *
 *  Created on: 2016/10/18
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
	Val s = 0;
	while (first!=last) {
		s = s + *first;
		++first;
	}
	return s;
}

struct Node { Node* next; int data; };
struct Node_iter { Node* pos; };

//Node_iter operator++(Node_iter& p) { return p.pos = p.pos->next; }
	// error: could not convert '(p.Node_iter::pos = p.Node_iter::pos->Node::next)' from 'Node*' to 'Node_iter'
Node_iter operator++(Node_iter& p) { p.pos = p.pos->next; return p; }
int operator*(Node_iter p) { return p.pos->data; }
bool operator!=(Node_iter p, Node_iter q) { return p.pos != q.pos; }

void test(Node* lst)
{
	//int s = sum<Node_iter,int>(lst,nullptr);
		// error: no matching function for call to 'sum(Node*&, std::nullptr_t)'
	int s = sum<Node_iter,int>({lst},{nullptr});
	cout << "test() s: " << s << '\n';
}

template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val s)
{
	while (first!=last) {
		s = s + *first;
		++first;
	}
	return s;
}

template<typename Iter, typename Val, typename Oper>
Val accumulate2(Iter first, Iter last, Val s, Oper op)
{
	while (first!=last) {
		s = op(s,*first);
		++first;
	}
	return s;
}

// add main

int main()
{
	double ad[] = {1,2,3,4};
	double s = sum<double*,double>(ad,ad+4);
	cout << "s: " << s << '\n';

	double s1 = accumulate(ad,ad+4,0.0);
	double s2 = accumulate(ad,ad+4,0);
	cout << "s1: " << s1 << '\n';
	cout << "s2: " << s2 << '\n';

	double s3 = accumulate2(ad,ad+4,0.0,std::plus<double>{});
	double s4 = accumulate2(ad,ad+4,1.0,std::multiplies<double>{});
	cout << "s3: " << s3 << '\n';
	cout << "s4: " << s4 << '\n';

	Node* head = new Node{nullptr, 1};
	head = new Node{head, 2};
	head = new Node{head, 3};
	test(head);
}

