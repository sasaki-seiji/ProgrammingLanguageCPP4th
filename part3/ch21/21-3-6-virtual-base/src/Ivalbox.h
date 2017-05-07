/*
 * Ivalbox.h
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#ifndef IVALBOX_H_
#define IVALBOX_H_

class Ival_box {
public:
	virtual int get_value() = 0;
	virtual void set_value(int i) = 0;
	virtual void reset_value(int i) = 0;
	virtual void prompt() = 0;
	virtual bool was_changed() const = 0;
	virtual ~Ival_box() { }

	// 2017.04.30 add
	virtual void display_info() const = 0;
};

#endif /* IVALBOX_H_ */
