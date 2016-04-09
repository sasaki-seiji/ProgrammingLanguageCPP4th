/*
 * Entry.h
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <string>
#include <istream>
#include <ostream>
using namespace std;

struct Entry {
	string name;
	int	number;
};

ostream& operator<<(ostream& os, const Entry& e);
istream& operator>>(istream& is, Entry& e);

#endif /* ENTRY_H_ */
