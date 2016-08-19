/*
 * user.cpp
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#include "List.h"
#include "List2.h"
#include <iostream>
using namespace std;

void test_list()
{
	List *head, *tail;

	head = tail = new List(0);
	for (int i = 1; i < 5; ++i)
		head = head->add_head(new List(i));

	List_iterator it{head};
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';

	for (int i = 1; i < 5; ++i)
		tail = head->add_tail(new List(-i));

	it.reset(head);
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';
}

void test_list2()
{
	List2 *head, *tail;

	head = tail = new List2(0);
	for (int i = 1; i < 5; ++i)
		head = head->add_head(new List2(i));

	List2_iterator it{head};
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';

	for (int i = 1; i < 5; ++i)
		tail = head->add_tail(new List2(-i));

	it.reset(head);
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';
}

int main()
{
	test_list();
	test_list2();
}

