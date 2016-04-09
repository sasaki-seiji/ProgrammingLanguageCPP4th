/*
 * count.h
 *
 *  Created on: 2016/03/28
 *      Author: sasaki
 */

#ifndef COUNT_H_
#define COUNT_H_

template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for (const auto& x : c)
		if (pred(x))
			++cnt;
	return cnt;
}

#endif /* COUNT_H_ */
