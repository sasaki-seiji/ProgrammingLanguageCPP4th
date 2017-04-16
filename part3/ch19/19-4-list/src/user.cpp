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
	List *head = nullptr;
	for (int i = 0; i < 5; ++i)
		head = new List(i, head);

	List_iterator it{head};
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';

	delete head;
}

void test_list2()
{
	List2 *head = nullptr;
	for (int i = 0; i < 5; ++i)
		head = new List2(i, head);

	List2_iterator it{head};
	while(int* p = it.next())
		cout << *p << ' ';
	cout << '\n';

	delete head;
}

int main()
{
	test_list();
	test_list2();
}

