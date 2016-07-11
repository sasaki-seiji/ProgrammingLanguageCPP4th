/*
 * main.cpp
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */


#include "dc.h"
#include <sstream>
#include <iostream>
using namespace std;
using namespace Lexer;
using namespace Table;
using namespace Error;

void Driver::calculate()
{
	for (;;){
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << Parser::expr(false) << '\n';
	}
}

int main()
{
	table["pi"] = 3.14159;
	table["e"] = 2.71828;

	Driver::calculate();

	return no_of_errors;
}
