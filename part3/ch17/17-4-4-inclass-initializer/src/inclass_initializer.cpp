/*
 * innerclass_initializer.cpp
 *
 *  Created on: 2016/07/29
 *      Author: sasaki
 */

#include <iostream>
using namespace std;


class A {
public:
	int a {7};
	int b = 77;
};

class A1 {
public:
	int a;
	int b;
	A1() : a{7}, b{77} { }
};

void test_inclass_initializer()
{
	cout << "-- test_inclass_initializer() --\n";

	A a0;
	cout << "a0.a: " << a0.a << '\n';
	cout << "a0.b: " << a0.b << '\n';

	A1 a1;
	cout << "a1.a: " << a1.a << '\n';
	cout << "a1.b: " << a1.b << '\n';
}

struct HashFunction {
	string func;
	HashFunction(string s) :func{s} { }
};

struct D {
	int x;
	D(int d) :x{d} { }
};

int g(D d)
{
	return d.x * 2;
}

class A2 {
public:
	A2() :a{7}, b{5}, algorithm{"MD5"}, state{"Constructor run"} { }
	A2(int a_val) :a{a_val}, b{5}, algorithm{"MD5"}, state{"Constructor run"} { }
	A2(D d) :a{7}, b{g(d)}, algorithm{"MD5"}, state{"Constructor run"} { }
	void print(ostream& os);
private:
	int a, b;
	HashFunction algorithm;
	string state;
};

void A2::print(ostream& os)
{
	os << "A2(a=" << a << ", b=" << b
		<< ", algorithm=" << algorithm.func << ", state=" << state << ")\n";
}

class A3 {
public:
	A3() :a{7}, b{5} { }
	A3(int a_val) :a{a_val}, b{5} { }
	A3(D d) :a{7}, b{g(d)} { }
	void print(ostream& os);
private:
	int a, b;
	HashFunction algorithm {"MD5"};
	string state {"Constructor run"};
};

void A3::print(ostream& os)
{
	os << "A3(a=" << a << ", b=" << b
		<< ", algorithm=" << algorithm.func << ", state=" << state << ")\n";
}

class A4 {
public:
	A4() { }
	A4(int a_val) :a{a_val} { }
	A4(D d) :b{g(d)} { }
	void print(ostream& os);
private:
	int a {7};
	int b {5};
	HashFunction algorithm {"MD5"};
	string state {"Constructor run"};
};

void A4::print(ostream& os)
{
	os << "A4(a: " << a << ", b: " << b
		<< ", algorithm: " << algorithm.func << ", state: " << state << ")\n";
}

void test_common_initializer()
{
	cout << "-- test_common_initializer() --\n";

	A2 a21;
	A2 a22 {10};
	A2 a23 {D{3}};
	cout << "A2 a21: "; a21.print(cout);
	cout << "A2 a22{10}: "; a22.print(cout);
	cout << "A2 a23{D{3}}: "; a23.print(cout);

	A3 a31;
	A3 a32 {10};
	A3 a33 {D{3}};
	cout << "A3 a31: "; a31.print(cout);
	cout << "A3 a32{10}: "; a32.print(cout);
	cout << "A3 a33{D{3}}: "; a33.print(cout);

	A4 a41;
	A4 a42 {10};
	A4 a43 {D{3}};
	cout << "A4 a41: "; a41.print(cout);
	cout << "A4 a42{10}: "; a42.print(cout);
	cout << "A4 a43{D{3}}: "; a43.print(cout);
}

int count = 0;
int count2 = 0;

int f(int i) { return i+count; }

struct S {
	int m1 {count2};
	int m2 {f(m1)};
	S() { ++count2; }
};

void test_initializer_depending_globalvar()
{
	cout << "-- test_initializer_depending_globalvar() --\n";
	S s1;
	++count;
	S s2;
	cout << "s1.m1: " << s1.m1 << ", s1.m2: " << s1.m2 << '\n';
	cout << "s2.m1: " << s2.m1 << ", s2.m2: " << s2.m2 << '\n';
}

// add main

int main()
{
	test_inclass_initializer();
	test_common_initializer();
	test_initializer_depending_globalvar();
}
