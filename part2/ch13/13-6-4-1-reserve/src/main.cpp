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

void test_reserve()
{
	cout << "-- test_reserve() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi(original): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(original): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;

	vi.reserve(100);
	vs.reserve(100);
	cout << "vi(reserved): " << vi << ", capacity = " << vi.capacity() << '\n'<< flush;
	cout << "vs(reserved): " << vs << ", capacity = " << vs.capacity() << '\n'<< flush;

}

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\") : success\n";

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		v1.reserve(10);
		cout << "v1.reserve(10) : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "v1(after reserve(10)): " << v1 << endl;
}

int main()
{
	test_reserve();

	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
