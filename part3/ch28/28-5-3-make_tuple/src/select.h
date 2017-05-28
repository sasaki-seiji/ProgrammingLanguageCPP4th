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
struct select_type;
	// error: ‘template<class T1, class T2, class T3, class T4> struct select’ redeclared as different kind of symbol

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
using Select = typename select_type<I,T1,T2,T3,T4>::type;

template<typename T1, typename T2, typename T3, typename T4>
struct select_type<0,T1,T2,T3,T4> { using type = T1; };

template<typename T1, typename T2, typename T3, typename T4>
struct select_type<1,T1,T2,T3,T4> { using type = T2; };

template<typename T1, typename T2, typename T3, typename T4>
struct select_type<2,T1,T2,T3,T4> { using type = T3; };

template<typename T1, typename T2, typename T3, typename T4>
struct select_type<3,T1,T2,T3,T4> { using type = T4; };

#endif /* SELECT_H_ */
