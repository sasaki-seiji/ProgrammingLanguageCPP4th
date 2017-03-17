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

template<typename T>
Vector<T> make_vector(size_t n, const T& val = T{})
{
	Vector<T> v(n, val);
	return v;
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

	Vector<int> vi3(12, 789);
	Vector<string> vs3(12, "ABC");
	cout << "vi3: " << vi3 << '\n'<< flush;
	cout << "vs3: " << vs3 << '\n'<< flush;

	// assign - shrink
	vi2 = vi;
	vs2 = vs;
	cout << "vi2(assigned from vi): " << vi2 << '\n'<< flush;
	cout << "vs2(assigned from vs): " << vs2 << '\n'<< flush;

	// assign - expand size
	vi2 = vi3;
	vs2 = vs3;
	cout << "vi2(assigned from vi3): " << vi2 << '\n'<< flush;
	cout << "vs2(assigned from vs3): " << vs2 << '\n'<< flush;

	// assign - expand size and space
	vi = vi3;
	vs = vs3;
	cout << "vi(assigned from vi3): " << vi << '\n'<< flush;
	cout << "vs(assigned from vs3): " << vs << '\n'<< flush;
}

void test_element_assign_fail()
{
	cout << "-- test_element_assign_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc")), v2(5,string("xyz"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\"), v2(5, \"xyz\") : success\n";

	Test_element<string>::trigger_assign_exception(3);
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

	Test_element<string>::verbose();
	test_element_assign_fail();
	Test_element<string>::display_counters();
}
