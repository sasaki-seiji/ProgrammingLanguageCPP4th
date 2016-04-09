/*
 * Less_than.h
 *
 *  Created on: 2016/03/28
 *      Author: sasaki
 */

#ifndef LESS_THAN_H_
#define LESS_THAN_H_

template<typename T>
class Less_than {
	const T val;
public:
	Less_than(const T& v) : val(v) { }
	bool operator()(const T& x) const { return x < val; }
};

#endif /* LESS_THAN_H_ */
