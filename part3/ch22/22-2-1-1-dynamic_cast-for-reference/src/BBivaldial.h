/*
 * BBivaldial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef BBIVALDIAL_H_
#define BBIVALDIAL_H_

#include "Ivaldial.h"
#include "BBdial.h"

class BB_ival_dial : public Ival_dial, protected BBdial {
public:
	BB_ival_dial(int ll, int hh) : BBdial{ll,hh} { }

	int get_value() { return BBdial::value(); }
	void set_value(int i) { BBdial::value(i); }
	void reset_value(int i) { BBdial::reset(i); }
	void prompt() { BBdial::prompt("BB_ival_dial"); }
	bool was_changed() const { return BBdial::was_changed(); }

	void right(int n) { BBdial::right(n); }
	void left(int n) { BBdial::left(n); }
};

#endif /* BBIVALDIAL_H_ */
