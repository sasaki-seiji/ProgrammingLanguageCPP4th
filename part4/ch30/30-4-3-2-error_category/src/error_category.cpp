/*
 * error_category.cpp
 *
 *  Created on: 2017/08/05
 *      Author: sasaki
 */

#include <system_error>
#include <future>
#include <iostream>
using namespace std;

int main()
{
	cout << "generic_category: " << generic_category().name() << endl;
	cout << "system_category: " << system_category().name() << endl;
	cout << "future_category: " << future_category().name() << endl;
	cout << "iostream_category: " << iostream_category().name() << endl;
}

