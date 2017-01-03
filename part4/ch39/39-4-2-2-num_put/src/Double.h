/*
 * Double.h
 *
 *  Created on: 2017/01/03
 *      Author: sasaki
 */

#ifndef DOUBLE_H_
#define DOUBLE_H_

#include <iostream>

struct Double {
	double v;
};

std::ostream& operator<<(std::ostream& os, Double d);


#endif /* DOUBLE_H_ */
