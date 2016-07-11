/*
 * main.cpp
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */


#include "parser.h"
#include "lexer.h"
#include "error.h"
#include "table.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace Lexer;
using Table::table;
using namespace Error;

namespace Driver {
	void calculate()
	{
		for (;;){
			ts.get();
			if (ts.current().kind == Kind::end) break;
			if (ts.current().kind == Kind::print) continue;
			cout << Parser::expr(false) << '\n';
		}
	}
}

int main()
{
	table["pi"] = 3.14159;
	table["e"] = 2.71828;

	Driver::calculate();

	return number_of_errors;
}
