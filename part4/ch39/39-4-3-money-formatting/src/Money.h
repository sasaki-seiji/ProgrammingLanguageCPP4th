/*
 * Money.h
 *
 *  Created on: 2017/01/04
 *      Author: sasaki
 */

#ifndef MONEY_H_
#define MONEY_H_

#include <iostream>
#include <locale>
using std::moneypunct;

struct Money {
	using Value = long long;
	Value amount;
};

class My_money_io : public moneypunct<char,true> {
public:
	explicit My_money_io(size_t r=0) : moneypunct<char,true>(r) { }

	char_type do_decimal_point() const override { return '.'; }
	char_type do_thousands_sep() const override { return ','; }
	string_type do_grouping() const override { return "\003\003\003"; }

	string_type do_curr_symbol() const override { return "USD "; }
	string_type do_positive_sign() const override { return ""; }
	string_type do_negative_sign() const override { return "-"; }

	int do_frac_digits() const override { return 2; }

	pattern do_pos_format() const override { return pat; }
	pattern do_neg_format() const override { return pat; }
private:
	static const pattern pat;
};



std::ostream& operator<<(std::ostream& s, Money m);

#endif /* MONEY_H_ */
