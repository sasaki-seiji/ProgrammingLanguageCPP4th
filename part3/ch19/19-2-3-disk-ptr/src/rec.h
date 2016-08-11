/*
 * rec.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef REC_H_
#define REC_H_

#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;

struct Rec {
	string name;
	int count {0};
};

istream& operator>>(istream& is, Rec& rec);
ostream& operator<<(ostream& os, const Rec& rec);

#endif /* REC_H_ */
