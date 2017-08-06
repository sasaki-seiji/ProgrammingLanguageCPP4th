/*
 * error_code_mapping.cpp
 *
 *  Created on: 2017/08/06
 *      Author: sasaki
 */


#include "my_future_errc.h"
#include <system_error>
#include <future>
#include <iostream>
using namespace std;

void test_future_errc()
{
	//error_code ec1 {7};
		//  error: no matching function for call to ‘std::error_code::error_code(<brace-enclosed initializer list>)’
	error_code ec2 {future_errc::no_state};
	cout << "error_code ec2 {future_errc::no_state}; " << ec2.message() << endl;

	ec2 = future_errc::promise_already_satisfied;
	cout << "ec2 = future_errc::promise_already_satisfied; " << ec2.message() << endl;

	//ec2 = errc::broken_pipe;
		// no match for ‘operator=’ (operand types are ‘std::error_code’ and ‘std::errc’)
}

void test_my_future_errc()
{
	error_code ec2 {my_future_errc::no_state};
	cout << "error_code ec2 {my_future_errc::no_state}; " << ec2.message() << endl;

	ec2 = my_future_errc::promise_already_satisfied;
	cout << "ec2 = my_future_errc::promise_already_satisfied; " << ec2.message() << endl;
}

int main()
{
	test_future_errc();
	test_my_future_errc();
}
