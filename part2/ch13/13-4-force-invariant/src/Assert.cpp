/*
 * Assert.cpp
 *
 *  Created on: 2016/05/16
 *      Author: sasaki
 */

#include <sstream>
#include "Assert.h"

namespace Assert {

	using std::ostringstream;

	string compose(const char* file, int line, const string& message)
	{
		ostringstream os ("(");
		//os << file << ";" << line << "):" << message;
		os << "(" << file << ";" << line << "):" << message;
		return os.str();
	}

} /* namespace Assert */
