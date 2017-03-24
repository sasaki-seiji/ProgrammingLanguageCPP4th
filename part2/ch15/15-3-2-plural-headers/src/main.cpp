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
using namespace Lexer;
using Table::table;
using namespace Error;

#include <sstream>
using namespace std;

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

int main(int argc, char* argv[])
{
	switch (argc){
	case 1:
		break;
	case 2:
		ts.set_input(new istringstream{argv[1]});
		break;
	default:
		error("too many arguments");
		return 1;
	}

	table["pi"] = 3.14159;
	table["e"] = 2.71828;

	Driver::calculate();

	return number_of_errors;
}
