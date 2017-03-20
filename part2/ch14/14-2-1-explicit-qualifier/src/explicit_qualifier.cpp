/*
 * explicit_qualifier.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

namespace Parser {
	double expr(bool);
	double term(bool);
	double prim(bool);
}

double val = Parser::expr(true);

double Parser::expr(bool)
{
	return 1.0;
}

//void Parser::logical(bool);
	// error: 'void Parser::logical(bool)' should have been declared inside 'Parser'
//double Parser::trem(bool);
	// error: 'double Parser::trem(bool)' should have been declared inside 'Parser'
//double Parser::prim(int);
	// error: 'double Parser::prim(int)' should have been declared inside 'Parser'

int f();

int g()
{
	int f;
	//f();
		// error: 'f' cannot be used as a function
	return ::f();
}

// undefs
int f()
{
	return 1;
}

int main()
{
	cout << "val = " << val << endl;
	cout << "g() returns " << g() << endl;
}
