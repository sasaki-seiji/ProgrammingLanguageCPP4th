/*
 * error_code.cpp
 *
 *  Created on: 2017/08/06
 *      Author: sasaki
 */

#include "open_file.h"
#include <iostream>
using namespace std;

void test_open_file(const string& path, const string& text)
{
	ofstream ofs;

	try {
		open_file(path, ofs);
		ofs << text << endl;
	}
	catch (system_error& e) {
		cout << "caught system error: " << e.what() << endl;
	}
}

int main()
{
	test_open_file("data/test.txt", "test data for \"data/test.txt\"");
	test_open_file("test.txt", "test data for \"test.txt\"");
	test_open_file("notexist/test.txt", "test data for \"notexist/test.txt\"");
	test_open_file("test.txt/notexist", "test data for \"test.txt/notexist\"");
}
