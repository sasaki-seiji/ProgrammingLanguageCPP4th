/*
 * Assoc.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef ASSOC_H_
#define ASSOC_H_

#include <string>
#include <vector>
#include <utility>
using std::vector;
using std::string;
using std::pair;

struct Assoc {
	vector<pair<string,int>> vec;

	const int& operator[](const string&) const;
	int& operator[](const string&);
};

struct Bad_index { };

#endif /* ASSOC_H_ */
