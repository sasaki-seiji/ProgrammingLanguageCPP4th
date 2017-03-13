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
		cout << "caught in f() as ios_base::failure&: " << e.what() << '\n';
		// ...
	}
	catch (std::exception& e) {
		cout << "caught in f() as exception&: " << e.what() << '\n';
		// ...
	}
	catch (...) {
		cout << "caught in f() as ...\n";
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
		// error: '...' handler must be the last handler for its try block [-fpermissive]
	catch (std::exception& e) {
		cout << "caught in g() as exception&: " << e.what() << endl ;
		// ...
	}
	catch (std::bad_cast& e) {
		// warning: exception of type ‘std::bad_cast’ will be caught
		cout << "caught in g() as bad_cast" << e.what() << endl;
		// ...
	}
}

int main()
{
	f();
	g();

}
