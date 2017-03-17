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

void test_safe_assign()
{
	cout << "-- test_safe_assign() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n'<< flush;
	cout << "vs: " << vs << '\n'<< flush;

	Vector<int> vi2(15, 456);
	Vector<string> vs2(15, "xyz");
	cout << "vi2: " << vi2 << '\n'<< flush;
	cout << "vs2: " << vs2 << '\n'<< flush;

	// safe assign
	safe_assign(vi2, vi);
	safe_assign(vs2, vs);
	cout << "vi2(safe assigned from vi): " << vi2 << '\n'<< flush;
	cout << "vs2(safe assigned from vs): " << vs2 << '\n'<< flush;
}

void test_safe_assign_by_value()
{
	cout << "-- test_safe_assign_by_value() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n'<< flush;
	cout << "vs: " << vs << '\n'<< flush;

	Vector<int> vi2(15, 456);
	Vector<string> vs2(15, "xyz");
	cout << "vi2: " << vi2 << '\n'<< flush;
	cout << "vs2: " << vs2 << '\n'<< flush;

	// safe assign by value
	safe_assign_by_value(vi2, vi);
	safe_assign_by_value(vs2, vs);
	cout << "vi2(safe assigned by value from vi): " << vi2 << '\n'<< flush;
	cout << "vs2(safe assigned by value from vs): " << vs2 << '\n'<< flush;
}

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc")), v2(5,string("xyz"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\"), v2(5, \"xyz\") : success\n";

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		safe_assign(v2,v1);
		cout << "safe_assign(v2,v1) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "v2(after safe_assign): " << v2 << endl;

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		safe_assign_by_value(v2,v1);
		cout << "safe_assign_by_value(v2,v1) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "v2(after safe_assign_by_value): " << v2 << endl;
}

int main()
{
	test_safe_assign();
	test_safe_assign_by_value();

	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
