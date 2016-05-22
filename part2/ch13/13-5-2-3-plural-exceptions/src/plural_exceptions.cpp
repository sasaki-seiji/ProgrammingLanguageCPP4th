/*
 * plural_exceptions.cpp
 *
 *  Created on: 2016/05/19
 *      Author: sasaki
 */

#include <stdexcept>
#include <iostream>
#include <typeinfo>
using namespace std;

void f()
{
	try {
		throw std::runtime_error{"runtime error"};
		// ...
	}
	catch (std::ios_base::failure& e) {
		cerr << e.what() << '\n';
		// ...
	}
	catch (std::exception& e) {
		cerr << e.what() << '\n';
		// ...
	}
	catch (...) {
		cerr << "some excetption\n";
		// ...
	}
}

void g()
{
	try {
		throw std::bad_cast{};
		// ...
	}
	//catch (...) {
	//	// ...
	//}
		// '...' handler must be the last handler for its try block [-fpermissive]
	catch (std::exception& e) {
		cerr << "caught exception\n";
		// ...
	}
	catch (std::bad_cast) {
		cerr << "caught bad_cast\n";
		// ...
	}
}

int main()
{
	f();
	g();

}
