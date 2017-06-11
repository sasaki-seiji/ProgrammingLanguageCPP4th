/*
 * lifting.cpp
 *
 *  Created on: 2016/10/18
 *      Author: sasaki
 */

#include "sum.h"
#include "Node.h"
#include "accumulate.h"

#include <iostream>
using namespace std;

void test(Node* lst)
{
	cout << "-- test(Node*) --\n";

	//int s = sum<Node_iter,int>(lst,nullptr);
		// error: no matching function for call to 'sum(Node*&, std::nullptr_t)'
	int s = sum<Node_iter,int>({lst},{nullptr});
	cout << "s: " << s << '\n';
}


// add main

int main()
{
	double ad[] = {1.1, 2.1, 3.1, 4.1};
	double s = sum<double*,double>(ad,ad+4);
	cout << "s: " << s << '\n';

	Node* head = new Node{nullptr, 1};
	head = new Node{head, 2};
	head = new Node{head, 3};
	test(head);

	double s1 = accumulate(ad,ad+4,0.0);
	cout << "s1: " << s1 << '\n';
	double s2 = accumulate(ad,ad+4,0);
	cout << "s2: " << s2 << '\n';

	double s3 = accumulate(ad,ad+4,0.0,std::plus<double>{});
	cout << "s3: " << s3 << '\n';
	double s4 = accumulate(ad,ad+4,1.0,std::multiplies<double>{});
	cout << "s4: " << s4 << '\n';
}

