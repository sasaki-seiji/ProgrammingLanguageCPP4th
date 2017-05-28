/*
 * Fac.h
 *
 *  Created on: 2017/05/28
 *      Author: sasaki
 */

#ifndef FAC_H_
#define FAC_H_


template<int N>
struct Fac {
	static const int value = N*Fac<N-1>::value;
};

template<>
struct Fac<1> {
	static const int value = 1;
};




#endif /* FAC_H_ */
