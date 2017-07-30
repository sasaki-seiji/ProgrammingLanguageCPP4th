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


int main()
try {
	throw My_error{119};
}
catch (My_error& me) {
	cout << "My_error - interesting_value: " << me.interesting_value << ", what(): " << me.what() << endl;
}
catch (runtime_error& re) {

}
catch (exception& e)
{

}
catch (...) {

}
