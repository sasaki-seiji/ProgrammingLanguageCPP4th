/*
 * driver.cpp
 *
 *  Created on: 2016/05/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "driver.h"
#include "lexer.h"
#include "parser.h"
#include "table.h"
#include "error.h"

using Table::table;
using namespace Parser;
using namespace Error;
using namespace Lexer;

void Driver::calculate()
{
	for (;;){
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
	}
}

int main()
{
	table["pi"] = 3.14159;
	table["e"] = 2.71828;

	Driver::calculate();

	return no_of_errors;
}



