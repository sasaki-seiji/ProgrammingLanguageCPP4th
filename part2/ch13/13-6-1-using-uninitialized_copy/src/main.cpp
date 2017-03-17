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

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<int>> v1(5, 1);
	cout << "Vector<Test_element<int>> v1(5, 1) : success\n";

	Test_element<int>::trigger_copy_construct_exception(3);
	try {
		Vector<Test_element<int>> v2(5,2);
		cout << "Vector<Test_element<int>> v2(5,2) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int main()
{
	Test_element<int>::verbose();
	test_element_copy_fail();
	Test_element<int>::display_counters();
}
