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


void test_assign()
{
	cout << "-- test_assign() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n'<< flush;
	cout << "vs: " << vs << '\n'<< flush;

	Vector<int> vi2(15, 456);
	Vector<string> vs2(15, "xyz");
	cout << "vi2: " << vi2 << '\n'<< flush;
	cout << "vs2: " << vs2 << '\n'<< flush;

	// assign
	vi2 = vi;
	vs2 = vs;
	cout << "vi2(assigned from vi): " << vi2 << '\n'<< flush;
	cout << "vs2(assigned from vs): " << vs2 << '\n'<< flush;
}

void test_swap()
{
	cout << "-- test_swap() --\n";

	Vector<string> vs(5, "abc");
	Vector<string> vs2(10, "xyz");
	cout << "vs: " << vs << endl;
	cout << "vs2: " << vs2 << endl;

	// swap
	swap(vs,vs2);
	cout << "vs(swapped with vs2): " << vs << endl;
	cout << "vs2(swapped with vs): " << vs2 << endl;
}

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc")), v2(5,string("xyz"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\"), v2(5, \"xyz\") : success\n";

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		v2 = v1;
		cout << "v2 = v1 : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << "v2(after assign): " << v2 << endl;
}

int main()
{
	test_assign();
	test_swap();

	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
