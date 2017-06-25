/*
 * test_slice.cpp
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */


#include "slice.h"
#include <iostream>
using namespace std;

void test_slice_ctor()
{
	cout << "-- test_slice_ctor() --\n";

	slice s1;
	slice s2{3};
	slice s3{3,10};
	slice s4{3,10,2};

	cout << "s1: " << s1 << endl;
	cout << "s2{3}: " << s2 << endl;
	cout << "s3{3,10}: " << s3 << endl;
	cout << "s4{3,10,2}: " << s4 << endl;
}

void test_slice_call()
{
	cout << "-- test_slice_call() --\n";

	slice s{3,10,2};

	cout << "s{3,10,2}: " << s << endl;
	cout << "s(0): " << s(0) << endl;
	cout << "s(5): " << s(5) << endl;
}
