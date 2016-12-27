/*
 * standard_manipulator.cpp
 *
 *  Created on: 2016/12/27
 *      Author: sasaki
 */


#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void ios_manip()
{
	cout << 1234 << ',' << hex << 1234 << ',' << oct << 1234 << dec << '\n';

	constexpr double d = 123.456;

	cout << d << "; "
		<< scientific << d << "; "
		<< hexfloat << d << "; "
		<< fixed << d << "; "
		<< defaultfloat << d << '\n';

	cout << "Hello, World!\n";
	cout << "Hello, World!" << endl;
}

void manip_with_param()
{
	cout << '(' << setw(4) << setfill('#') << 12 << ")(" << 12 << ")\n";
}

void test_skipws()
{
	string input {"0 1 2 3 4"};

	istringstream iss {input};
	string s;
	for  (char ch; iss>>ch; )
		s += ch;
	cout << s << endl;

	istringstream iss2 {input};
	string s2;
	iss2 >> noskipws;
	for (char ch; iss2>>ch; )
		s2 += ch;
	cout << s2 << endl;
}

int main()
{
	ios_manip();
	manip_with_param();
	test_skipws();
}

