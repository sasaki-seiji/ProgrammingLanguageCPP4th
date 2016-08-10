/*
 * Tiny.h
 *
 *  Created on: 2016/08/10
 *      Author: sasaki
 */

#ifndef TINY_H_
#define TINY_H_

class Tiny {
	char v;
	void assign(int i) { if (i&~077) throw Bad_range(); v=i; }
public:
	class Bad_range { };

	Tiny(int i) { assign(i); }
	Tiny& operator=(int i) { assign(i); return *this; }

	operator int() const { return v; };
};



#endif /* TINY_H_ */
