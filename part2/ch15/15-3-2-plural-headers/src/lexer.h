/*
 * lexer.h
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <iostream>

namespace Lexer {
	enum class Kind : char {
		name, number, end,
		plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
	};

	struct Token {
		Kind kind;
		std::string string_value;
		double number_value;
	};

	class Token_stream {
	public:
		Token_stream(std::istream& s) : ip{&s}, owns{false} { }
		Token_stream(std::istream* p) : ip{p}, owns{true} { }

		~Token_stream() { close(); }

		Token get();
		const Token& current() { return ct; }

		void set_input(std::istream& s) { close(); ip = &s; owns = false; }
		void set_input(std::istream* p) { close(); ip = p; owns = true; }

	private:
		void close() { if (owns) delete ip; }

		std::istream* ip;
		bool owns;
		Token ct {Kind::end};
	};

	extern Token_stream ts;
}


#endif /* LEXER_H_ */
