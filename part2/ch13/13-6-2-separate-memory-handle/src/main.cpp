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

void test_copy()
{
	cout << "-- test_copy() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';

	// copy
	Vector<int> vi2{vi};
	Vector<string> vs2{vs};
	cout << "vi2(copied): " << vi2 << '\n';
	cout << "vs2(copied): " << vs2 << '\n';
}

void test_move()
{
	cout << "-- test_move() --\n";

	Vector<int> vi(10, 123);
	Vector<string> vs(10, "abc");
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';

	// move
	Vector<int> vi2{move(vi)};
	Vector<string> vs2{move(vs)};
	cout << "vi2(moved from vi): " << vi2 << '\n';
	cout << "vs2(moved from vs): " << vs2 << '\n';
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';
}

void test_move_assign()
{
	cout << "-- test_move_assign() --\n";

	Vector<int> vi(10, 123), vi2(5, 456);
	Vector<string> vs(10, "abc"), vs2(5, "xyz");
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';
	cout << "vi2: " << vi2 << '\n';
	cout << "vs2: " << vs2 << '\n';

	// move assign
	vi2 = move(vi);
	vs2 = move(vs);
	cout << "vi2(move assigned from vi): " << vi2 << '\n';
	cout << "vs2(move assigned from vs): " << vs2 << '\n';
	cout << "vi: " << vi << '\n';
	cout << "vs: " << vs << '\n';

	// move assign from temporary object
	vi2 = Vector<int>(7, 789);
	vs2 = Vector<string>(7, "ABC");
	cout << "vi2(move assigned from temporary): " << vi2 << '\n';
	cout << "vs2(move assigned from temporary): " << vs2 << '\n';
}

void test_element_copy_fail()
{
	cout << "-- test_element_copy_fail() --\n";

	Vector<Test_element<string>> v1(5, string("abc"));
	cout << "Vector<Test_element<string>> v1(5, \"abc\") : success\n";

	Test_element<string>::trigger_copy_construct_exception(3);
	try {
		Vector<Test_element<string>> v2{v1};
		cout << "Vector<Test_element<string>> v2{v1} : success\n";
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}
}

int main()
{
	test_copy();
	test_move();
	test_move_assign();

	Test_element<string>::verbose();
	test_element_copy_fail();
	Test_element<string>::display_counters();
}
