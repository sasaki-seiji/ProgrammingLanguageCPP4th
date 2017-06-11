/*
 * concrete_example.cpp
 *
 *  Created on: 2016/10/18
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

double add_all(double* array, int n)
{
	double s {0};
	for (int i = 0; i<n; ++i)
		s = s + array[i];
	return s;
}

struct Node {
	Node* next;
	int data;
};

int sum_element(Node* first, Node* last)
{
	int s = 0;
	while (first!=last) {
		s += first->data;
		first = first->next;
	}
	return s;
}

// add main

int main()
{
	double array[] = { 1.2, 2.3, 3.4, 4.5 };
	double d_sum = add_all(array, sizeof(array)/sizeof(array[0]));
	cout << "d_sum: " << d_sum << '\n';

	Node *root = new Node{nullptr, 1};
	root = new Node{root, 2};
	root = new Node{root, 3};
	root = new Node{root, 4};
	int i_sum = sum_element(root, nullptr);
	cout << "i_sum: " << i_sum << '\n';

	while (root) {
		Node *p = root;
		root = p->next;
		delete p;
	}
}

