/*
 * reference_to_reference.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

using rr_i = int&&;
using lr_i = int&;
using rr_rr_i = rr_i&&;	// int&&
using lr_rr_i = rr_i&;	// int&
using rr_lr_i = lr_i&&;	// int&
using lr_lr_i = lr_i&;	// int&

int i;
//int && & r = i;
	// cannot declare reference to 'int&&', which is not a typedef or a template type argument

int main()
{
	cout << boolalpha;
	cout << "is_same<rr_rr_i,rr_i> ? " << is_same<rr_rr_i,rr_i>::value << endl;
	cout << "is_same<lr_rr_i,lr_i> ? " << is_same<lr_rr_i,lr_i>::value << endl;
	cout << "is_same<rr_lr_i,lr_i> ? " << is_same<rr_lr_i,lr_i>::value << endl;
	cout << "is_same<lr_lr_i,lr_i> ? " << is_same<lr_lr_i,lr_i>::value << endl;
}
