/*
 * Storable.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef STORABLE_H_
#define STORABLE_H_

#include <string>
using std::string;

struct Storable {
	virtual string get_file() = 0;
	virtual void read() = 0;
	virtual void write() = 0;

	virtual ~Storable() { }
};

#endif /* STORABLE_H_ */
