/*
 * rethrow.cpp
 *
 *  Created on: 2016/05/18
 *      Author: sasaki
 */

#include <stdexcept>
#include <iostream>
using namespace std;

bool can_handle_it_completely = true;

void h()
{
	try {
		//..
		throw std::out_of_range{"out of range"};
	}
	catch (std::exception& err) {
		if (can_handle_it_completely) {
			//.. handle it
			cout << "h() handled exception completely\n";
			return;
		}
		else {
			//.. handle partially
			cout << "h() rethrow exception\n";
			throw;
		}
	}
}

int main()
{
	try {
		can_handle_it_completely = true;
		h();
		can_handle_it_completely = false;
		h();
	}
	catch (std::exception& err) {
		cerr << err.what() << '\n';
	}
}
