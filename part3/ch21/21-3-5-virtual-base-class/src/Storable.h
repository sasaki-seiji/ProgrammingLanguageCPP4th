/*
 * Storable.h
 *
 *  Created on: 2016/09/01
 *      Author: sasaki
 */

#ifndef STORABLE_H_
#define STORABLE_H_

#include <string>
using std::string;

class Storable {
public:
	Storable(const string& s) : file_name{s} { }
	virtual void read() = 0;
	virtual void write() = 0;
	virtual ~Storable() { }
protected:
	string file_name;

	Storable(const Storable&) = delete;
	Storable& operator=(const Storable&) = delete;
};

#endif /* STORABLE_H_ */
