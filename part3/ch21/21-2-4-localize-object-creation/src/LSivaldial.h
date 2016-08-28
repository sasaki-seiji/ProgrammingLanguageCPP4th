/*
 * LSivaldial.h
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#ifndef LSIVALDIAL_H_
#define LSIVALDIAL_H_

#include "Ivaldial.h"
#include "LSdial.h"

class LS_ival_dial : public Ival_dial, protected LSdial {
public:
	LS_ival_dial(int ll, int hh) : LSdial{ll,hh} { }

	int get_value() { return LSdial::get_value(); }
	void set_value(int i) { LSdial::set_value(i); }
	void reset_value(int i) { LSdial::reset_value(i); }
	void prompt() { LSdial::prompt("LS_ival_dial"); }
	bool was_changed() const { return LSdial::was_changed(); }

	void right(int n) { LSdial::right(n); }
	void left(int n) { LSdial::left(n); }
};

#endif /* LSIVALDIAL_H_ */
