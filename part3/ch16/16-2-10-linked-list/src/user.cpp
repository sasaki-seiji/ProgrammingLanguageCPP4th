/*
 * user.cpp
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */


#include "Link.h"
#include <iostream>
using namespace std;

void print_tree(const Link *head)
{
	const Link *cur = head;
	while (cur) {
		cout << cur->data << ", ";
		cur = cur->suc;
	}
	cout << endl;
}

void delete_tree(Link *head)
{
	Link *cur = head;
	while (cur) {
		print_tree(cur);
		Link *next = cur->suc;
		cur->remove();
		cur = next;
	}
}

int main()
{
	Link *head = new Link{nullptr, nullptr, 10};

	for (int i = 0; i < 5; ++i) {
		head = head->insert(i*i);
	}

	print_tree(head);
	delete_tree(head);
}
