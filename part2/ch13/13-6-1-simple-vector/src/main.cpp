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

	Vector<Test_element<string>> v1(5, string("abc"));
	cout << "Vector<Test_element<string>> v1(5, string(\"abc\")) : success\n";

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		Vector<Test_element<string>> v2(5,string("xyz"));
		cout << "Vector<Test_element<string>> v2(5,string(\"xyz\")) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int main()
{
	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
