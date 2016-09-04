/*
 * Ioobj.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef IOOBJ_H_
#define IOOBJ_H_

#include <iostream>
#include <string>
#include <map>
using std::istream;
using std::string;
using std::map;

class Unknown_class { };

class Io_obj {
public:
	virtual Io_obj* clone() const = 0;
	virtual ~Io_obj() { }
};

//using Pf = Io_obj*(istream&);
using Pf = Io_obj*(*)(istream&);

extern map<string, Pf> io_map;

Io_obj* get_obj(istream&);

#endif /* IOOBJ_H_ */
