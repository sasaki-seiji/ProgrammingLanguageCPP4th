/*
 * user.cpp
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */


#include "Buffer.h"
#include "Circularbuffer.h"
#include "Buffer2.h"
#include <iostream>
using namespace std;

void test_Circular_buffer()
{
	cout << "-- test_Circular_buffer() --\n";

	Circular_buffer buf;

	for (char c = 'a'; c <= 'z'; ++c)
		buf.push_back(c);
	for (char c = 'A'; c <= 'Z'; ++c)
		buf.push_back(c);
	for (char c = '0'; c <= '9'; ++c)
		buf.push_back(c);
	buf.push_back('+');
	buf.push_back('-');
	buf.push_back('*');
	buf.push_back('/');
	buf.push_back('=');
	buf.push_back('^');
	buf.push_back('~');
	buf.push_back('&');
	buf.push_back('|');
	buf.push_back('(');
	buf.push_back(')');

	for (int i = 0; i < buf.length(); ++i)
		cout << buf[i] << ' ';
	cout << '\n';
}

void test_cross_derived_access()
{
	cout << "-- test_cross_derived_access() --\n";

	Circular_buffer2 cbuf2;
	Linked_buffer2 rbuf2;
	cbuf2.f(&rbuf2);
}

int main()
{
	test_Circular_buffer();
	test_cross_derived_access();
}
