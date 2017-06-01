/*
 * sum.h
 *
 *  Created on: 2017/06/01
 *      Author: sasaki
 */

#ifndef SUM_H_
#define SUM_H_

#include <vector>
#include <iostream>
extern bool tracing;

template<typename T>
T sum(std::vector<T>& v)
{
	T t {};
	if (tracing)
		std::cerr << "sum(" << &v << ")\n";
	//for (int i = 0; i!=v.size(); ++i)
	for (size_t i = 0; i!=v.size(); ++i)
		t = t + v[i];
	return t;
}


#endif /* SUM_H_ */
