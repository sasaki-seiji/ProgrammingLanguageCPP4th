/*
 * constructor.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

void simple()
{
	string s0;
	string s1 {"As simple as that!"};
	string s2 {s1};

	cout << "s0: \"" << s0 << "\"" << endl;
	cout << "s1: \"" << s1 << "\"" << endl;
	cout << "s2: \"" << s2 << "\"" << endl;
}

void trouble()
{
	//string s3 {7};
	//string s3 (7);
		// error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(int)'
	//string s4 {'a'};
	//string s4 ('a');
		// error: no matching function for call to 'std::__cxx11::basic_string<char>::basic_string(char)'
	//string s5 {7, 'a'};
	string s5 (7, 'a');
	//string s6 {0};
	//string s6 (0);	// crash!!!

	cout << "s5: \"" << s5 << "\"" << endl;

	const char* p = 0;
	//string s6(0);	// crash!!!
	//string s7{p};	// crash!!!
	string s8{"OK"};

	cout << "s8: \"" << s8 << "\"" << endl;

	try {
		string s9 (string::npos, 'x');
		cout << "success to construct s9" << endl;
	}
	catch (length_error &e) {
		cerr << e.what() << endl;
	}
}

void substring()
{
	string ss {"Fleetwood Mac"};
	string ss2 {ss, 0, 9};
	string ss3 {ss, 10, string::npos};

	cout << "ss: \"" << ss << "\"" << endl;
	cout << "ss2: \"" << ss2 << "\"" << endl;
	cout << "ss3: \"" << ss3 << "\"" << endl;
}

int main()
{
	simple();
	trouble();
	substring();
}

