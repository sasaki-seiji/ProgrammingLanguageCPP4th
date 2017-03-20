/*
 * Estd.h
 *
 *  Created on: 2016/05/27
 *      Author: sasaki
 */

#ifndef ESTD_H_
#define ESTD_H_

#include <algorithm>
namespace Estd {
	//using namespace std;
	template<typename C>
		void sort(C& c) { std::sort(c.begin(), c.end()); }
	template<typename C, typename P>
		void sort(C& c, P p) { std::sort(c.begin(), c.end(), p); }
}


#endif /* ESTD_H_ */
