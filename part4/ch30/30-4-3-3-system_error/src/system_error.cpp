/*
 * system_error.cpp
 *
 *  Created on: 2017/08/05
 *      Author: sasaki
 */

#include <system_error>
#include <iostream>
using namespace std;

int main()
{
	try {
		error_code ec(static_cast<int>(errc::invalid_argument),
	                       std::generic_category());

		throw system_error(ec, "system error!");

	}
	catch (system_error& err) {
		cout << "caught system_error " << err.what() << '\n';

		auto ec = err.code();
		cout << "category: " << ec.category().name() << '\n';
		cout << "value: " << ec.value() << '\n';
		cout << "message: " << ec.message() << '\n';
	}
}

