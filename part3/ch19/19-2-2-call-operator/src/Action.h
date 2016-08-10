/*
 * Action.h
 *
 *  Created on: 2016/08/11
 *      Author: sasaki
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <utility>
using std::pair;

struct Action {
	int operator()(int);
	pair<int,int> operator()(int,int);
	double operator()(double);
};

#endif /* ACTION_H_ */
