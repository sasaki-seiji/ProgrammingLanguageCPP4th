/*
 * error.h
 *
 *  Created on: 2016/05/24
 *      Author: sasaki
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <string>
namespace Error {
	using std::string;

	extern int no_of_errors;
	double error(const string& s);
}



#endif /* ERROR_H_ */
