/*
 * Club.h
 *
 *  Created on: 2016/07/28
 *      Author: sasaki
 */

#ifndef CLUB_H_
#define CLUB_H_

#include <string>
#include <vector>
using std::vector;
using std::string;

#include "Date.h"

class Club {
	string name;
	vector<string> members;
	vector<string> officers;
	Date founded;
public:
	Club(const string&n, Date fd);
	void print(ostream&);
};

#endif /* CLUB_H_ */
