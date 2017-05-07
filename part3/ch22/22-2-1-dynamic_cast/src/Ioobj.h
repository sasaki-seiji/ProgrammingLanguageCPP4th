/*
 * Ioobj.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef IOOBJ_H_
#define IOOBJ_H_

#include "Date.h"

class Io_obj {
public:
	virtual Io_obj* clone() = 0;
	virtual ~Io_obj() { }
};

class Io_date : public Date, public Io_obj {
public:
	Io_date(const Date& d) : Date{d} { }
	Io_date* clone() override { return new Io_date{*this}; }
};

#endif /* IOOBJ_H_ */
