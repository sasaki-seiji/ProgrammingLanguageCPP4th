/*
 * My_punct.h
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */

#ifndef MY_PUNCT_H_
#define MY_PUNCT_H_

#include <locale>
using std::numpunct;

class My_punct : public numpunct<char> {
public:
	explicit My_punct(size_t r = 0) : numpunct<char>(r) { }
protected:
	char do_decimal_point() const override { return ','; }
	char do_thousands_sep() const override { return '_'; }
	string do_grouping() const override { return "\003"; }
};




#endif /* MY_PUNCT_H_ */
