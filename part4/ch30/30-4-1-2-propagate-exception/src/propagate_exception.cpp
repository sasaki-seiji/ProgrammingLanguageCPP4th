/*
 * propagate_exception.cpp
 *
 *  Created on: 2017/07/31
 *      Author: sasaki
 */

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

struct My_error : runtime_error {
	My_error(const string& m) : runtime_error{m} { }
};

struct Some_error {
	Some_error(const string& m) : mes{m} { }
	string mes;
};

void my_code()
{
	try {
		throw Some_error{"some error occurred"};
	}
	catch (...) {
		My_error err {"something went wrong in my_code()"};

		throw_with_nested(err);
	}
}

void user()
{
	try {
		my_code();
	}
	catch(My_error& err) {
		cout << "My_error: " << err.what() << endl;

		try {
			rethrow_if_nested(err);
		}
		catch (Some_error& err2) {
			cout << "Some_error: " << err2.mes << endl;
		}
	}
}

int main()
{
	user();
}
