/*
 * exception_class_tree.cpp
 *
 *  Created on: 2017/07/30
 *      Author: sasaki
 */


#include <stdexcept>
#include <iostream>
using namespace std;

struct My_error : runtime_error {
	My_error(int x) : runtime_error{"My_error"}, interesting_value{x} { }
	int interesting_value;
};


void test_exception(int type)
try {
	cout << "-- test_exception(" << type << ") --\n";
	switch(type) {
	case 1:
		throw My_error{119};
	case 2:
		throw range_error("unexcepted range error occurred");
	case 3:
		throw out_of_range("out of range error occurred");
	default:
		throw int{110};
	}
}
catch (My_error& me) {
	cout << "My_error - interesting_value: " << me.interesting_value << ", what(): " << me.what() << endl;
}
catch (runtime_error& re) {
	cout << "runtime_error - what(): " << re.what() << endl;
}
catch (exception& e)
{
	cout << "exception - what(): " << e.what() << endl;
}
catch (...) {
	cout << "unknown error occurred" << endl;
}

int main()
{
	test_exception(1);
	test_exception(2);
	test_exception(3);
	test_exception(4);
}
