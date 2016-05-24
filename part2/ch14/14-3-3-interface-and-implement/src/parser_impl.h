/*
 * parser_impl.h
 *
 *  Created on: 2016/05/24
 *      Author: sasaki
 */

#ifndef PARSER_IMPL_H_
#define PARSER_IMPL_H_

#include "parser.h"
#include "lexer.h"
#include "error.h"
#include "table.h"

namespace Parser_impl {
	using namespace Parser;

	double prim(bool);
	double term(bool);

	using namespace Lexer;
	using Error::error;
	using Table::table;
}




#endif /* PARSER_IMPL_H_ */
