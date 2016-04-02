/*
 * input.cpp
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void f()
{
	int i;
	cin >> i;

	double d;
	cin >> d;

	cout << "input int is " << i << ", input double is " << d << '\n';
}

void hello()
{
	cout << "Please enter your name\n";
	string str;
	cin >> str;
	cout << "Hello, " << str << "!\n";
}

void hello_line()
{
	cout << "Please enter your name\n";
	string str;
	getline(cin, str);
	cout << "Hello, " << str << "!\n";
}

int main()
{
	f();
	hello();

	// 2016.04.02 add: discard rest input
	string buf;
	getline(cin, buf);

	hello_line();
}
