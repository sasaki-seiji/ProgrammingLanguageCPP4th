/*
 * main.cpp
 *
 *  Created on: 2016/05/21
 *      Author: sasaki
 */

#include <iostream>
#include <string>
using namespace std;
#include "vector.h"
#include "Test_element.h"

void test_construct()
{
	cout << "-- test_construct() --\n";

	Vector<Test_element> v1(5, 1);
	cout << "Vector<Test_element> v1(5, 1) : success\n";

	Test_element::trigger_copy_construct_exception(3);
	try {
		Vector<Test_element> v2(5,2);
		cout << "Vector<Test_element> v2(5,2) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int main()
{
	Test_element::verbose();
	test_construct();
	Test_element::display_counters();
}
