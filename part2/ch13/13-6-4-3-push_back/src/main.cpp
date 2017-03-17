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

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& v)
{
	os << '[';
	for (size_t i = 0 ; i != v.size(); ++i)
		os << v[i] << ',';
	os << "]";
	return os;
}

void test_push_back()
{
	cout << "-- test_push_back() --\n";

	Vector<int> vi(0);
	Vector<string> vs(0);

	for (int i = 0; i < 10; ++i) {
		vi.push_back(i*i);
		vs.push_back("xy");
	}
	cout << "vi: " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs: " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;
}

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\") : success\n";
	v1.reserve(10);
	cout << "v1.reserve(10) : success\n";

	Test_element<string>::trigger_copy_construct_exception(0);
	try {
		v1.push_back(string("xyz"));
		cout << "v1.push_back(string(\"xyz\")) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "v1(after push_back): " << v1 << endl;
}


int main()
{
	test_push_back();

	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
