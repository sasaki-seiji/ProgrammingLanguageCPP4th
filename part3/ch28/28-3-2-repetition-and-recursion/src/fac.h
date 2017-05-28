/*
 * fac.h
 *
 *  Created on: 2017/05/28
 *      Author: sasaki
 */

#ifndef FAC_H_
#define FAC_H_


template<int N>
constexpr int fac()
{
	return N*fac<N-1>();
}

template<>
constexpr int fac<1>()
{
	return 1;
}

constexpr int fac2(int i)
{
	return (i<2)?1:i*fac2(i-1);
}


#endif /* FAC_H_ */
