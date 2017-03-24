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

void Driver::calculate()
{
	for (;;){
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << Parser::expr(false) << '\n';
	}
}

int main(int argc, char* argv[])
{
	switch (argc){
	case 1:
		break;
	case 2:
		ts.set_input(new istringstream{argv[1]});
		break;
	default:
		Error::error("too many arguments");
		return 1;
	}

	Table::table["pi"] = 3.14159;
	Table::table["e"] = 2.71828;

	Driver::calculate();

	return Error::no_of_errors;
}
