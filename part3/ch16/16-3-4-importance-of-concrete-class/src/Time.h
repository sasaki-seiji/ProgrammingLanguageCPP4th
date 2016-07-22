/*
 * Time.h
 *
 *  Created on: 2016/07/22
 *      Author: sasaki
 */

#ifndef TIME_H_
#define TIME_H_

namespace Chrono {

class Time {
	int h, m, s;
public:
	Time(int hh =0, int mm =0, int ss =0) : h{hh}, m{mm}, s{ss} { }
	int hour() const { return h; }
	int minute() const { return m; }
	int second() const { return s; }
};

} /* namespace Chrono */

#endif /* TIME_H_ */
