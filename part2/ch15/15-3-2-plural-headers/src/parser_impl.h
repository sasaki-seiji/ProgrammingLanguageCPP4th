/*
 * parser_impl.h
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */

#ifndef PARSER_IMPL_H_
#define PARSER_IMPL_H_

#include "parser.h"
#include "error.h"
#include "lexer.h"

using Error::error;
using namespace Lexer;

namespace Parser {
	double prim(bool get);
	double term(bool get);
	double expr(bool get);
}


#endif /* PARSER_IMPL_H_ */
