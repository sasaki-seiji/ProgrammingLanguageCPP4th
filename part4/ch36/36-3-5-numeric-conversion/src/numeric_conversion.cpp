/*
 * numeric_conversion.cpp
 *
 *  Created on: 2016/12/18
 *      Author: sasaki
 */


#include <string>
#include <iostream>
using namespace std;


void test_stox()
{
	string s = "123.45";
	auto x1 = stoi(s);
	auto x2 = stod(s);

	cout << "x1: " << x1 << endl;
	cout << "x2: " << x2 << endl;
}

void test_stox_with_counter()
{
	string ss = "123.4567801234";
	size_t dist = 0;
	auto x = stoi(ss,&dist);
	++dist;
	auto y = stoll(&ss[dist]);

	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}

void stox_skip_head_space()
{
	string s = "   123.45";
	auto x1 = stoi(s);

	cout << "x1: " << x1 << endl;
}

void test_stox_with_base()
{
	string s4 = "149F";
	auto x5 = stoi(s4);
	auto x6 = stoi(s4,nullptr,10);
	auto x7 = stoi(s4,nullptr,8);
	auto x8 = stoi(s4,nullptr,16);

	string s5 = "1100101010100101";
	auto x9 = stoi(s5,nullptr,2);

	cout << "x5: " << x5 << endl;
	cout << "x6: " << x6 << endl;
	cout << "x7(oct): " << oct << x7 << endl;
	cout << "x8(hex): " << hex << x8 << endl;
	cout << "x9(hex): " << hex << x9 <<  endl;
}

void test_exception()
{
	try {
		auto x = stoi("Hello, World!");
		cout << "x: " << x << endl;
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}

	try {
		auto x = stoi("12345678901234567890");
		cout << "x: " << x << endl;
	}
	catch (out_of_range& e)
	{
		cerr << e.what() << endl;
	}

	try {
		auto x = stof("123456789e1000");
		cout << "x: " << x << endl;
	}
	catch (out_of_range& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	test_stox();
	test_stox_with_counter();
	stox_skip_head_space();
	test_stox_with_base();
	test_exception();
}

