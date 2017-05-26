/*
 * my_conditional.h
 *
 *  Created on: 2017/05/26
 *      Author: sasaki
 */

#ifndef MY_CONDITIONAL_H_
#define MY_CONDITIONAL_H_


template<bool C, typename T, typename F>
struct my_conditional {
	using type = T;
};

template<typename T, typename F>
struct my_conditional<false,T,F> {
	using type = F;
};

template<bool B, typename T, typename F>
using My_conditional = typename my_conditional<B,T,F>::type;



#endif /* MY_CONDITIONAL_H_ */
