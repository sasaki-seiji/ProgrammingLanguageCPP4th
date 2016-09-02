/*
 * Ivalslider.h
 *
 *  Created on: 2016/09/02
 *      Author: sasaki
 */

#ifndef IVALSLIDER_H_
#define IVALSLIDER_H_

class Ival_slider {
public:
	virtual int get_value() = 0;
	virtual void set_value(int i) = 0;
	virtual void reset_value(int i) = 0;
	virtual void prompt() = 0;
	virtual bool was_changed() const = 0;

	virtual void up() = 0;
	virtual void down() = 0;

	virtual ~Ival_slider() { }
};

#endif /* IVALSLIDER_H_ */
