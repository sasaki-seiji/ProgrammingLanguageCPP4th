/*
 * error.h
 *
 *  Created on: 2016/07/11
 *      Author: sasaki
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <string>

namespace Error {
	extern int number_of_errors;
	double error(const std::string&);
}

#endif /* ERROR_H_ */
