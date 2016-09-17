/*
 * ourt.h
 *
 *  Created on: 2016/09/17
 *      Author: sasaki
 */

#ifndef OUT_H_
#define OUT_H_

#include <iostream>

template<typename T>
void out(const T& t)
{
	std::cerr << t;
}


#endif /* OUT_H_ */
