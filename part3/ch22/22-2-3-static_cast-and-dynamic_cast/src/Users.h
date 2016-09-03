/*
 * Users.h
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */

#ifndef USERS_H_
#define USERS_H_

#include <set>
#include <string>
using std::set;
using std::string;

struct Person {
	string name;
	string addr;
};

class Users : private set<Person> {
public:
	virtual ~Users() { }
};

#endif /* USERS_H_ */
