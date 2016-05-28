/*
 * explicit_qualifier.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */


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
	// 'void Parser::logical(bool)' should have been declared inside 'Parser'
//double Parser::trem(bool);
	// 'double Parser::trem(bool)' should have been declared inside 'Parser'
//double Parser::prim(int);
	// 'double Parser::prim(int)' should have been declared inside 'Parser'

int f();

int g()
{
	int f;
	//f();
		// 'f' cannot be used as a function
	::f();
}

// undefs
int f()
{
	return 1;
}
