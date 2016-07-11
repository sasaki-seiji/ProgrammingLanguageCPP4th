/*
 * lexer.cpp
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */

#include "dc.h"
#include <cctype>
#include <iostream>

Lexer::Token Lexer::Token_stream::get()
{
	char ch = 0;
	*ip >> ch;

	switch (ch){
	case 0:
		return ct={Kind::end};
	case ';':
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return ct={static_cast<Kind>(ch)};
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		ip->putback(ch);
		*ip >> ct.number_value;
		ct.kind = Kind::number;
		return ct;
	default:
		if (isalpha(ch)){
			ip->putback(ch);
			*ip >> ct.string_value;
			ct.kind = Kind::name;
			return ct;
		}

		Error::error("bad token");
		return ct={Kind::print};
	}
}

Lexer::Token_stream Lexer::ts{cin};



