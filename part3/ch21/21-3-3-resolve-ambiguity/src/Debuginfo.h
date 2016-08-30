/*
 * Debuginfo.h
 *
 *  Created on: 2016/08/30
 *      Author: sasaki
 */

#ifndef DEBUGINFO_H_
#define DEBUGINFO_H_

#include <list>
#include <string>
#include <ostream>
using std::string;
using std::list;
using std::ostream;

using Debug_info = list<string>;

ostream& operator<<(ostream&, const Debug_info&);

Debug_info merge_info(Debug_info, Debug_info);

#endif /* DEBUGINFO_H_ */
