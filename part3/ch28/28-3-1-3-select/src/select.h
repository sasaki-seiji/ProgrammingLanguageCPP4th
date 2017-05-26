/*
 * select.h
 *
 *  Created on: 2016/10/06
 *      Author: sasaki
 */

#ifndef SELECT_H_
#define SELECT_H_

class Nil { };

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
struct myselect;

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
using Select = typename myselect<I,T1,T2,T3,T4>::type;

template<typename T1, typename T2, typename T3, typename T4>
struct myselect<0,T1,T2,T3,T4> { using type = T1; };

template<typename T1, typename T2, typename T3, typename T4>
struct myselect<1,T1,T2,T3,T4> { using type = T2; };

template<typename T1, typename T2, typename T3, typename T4>
struct myselect<2,T1,T2,T3,T4> { using type = T3; };

template<typename T1, typename T2, typename T3, typename T4>
struct myselect<3,T1,T2,T3,T4> { using type = T4; };

#endif /* SELECT_H_ */
