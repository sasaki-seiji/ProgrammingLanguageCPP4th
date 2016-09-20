/*
 * List2.h
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */

#ifndef LIST2_H_
#define LIST2_H_

template<typename T>
class List2 ;

template<typename T>
class List2<T*> {
	T*	p;
public:
	List2(T* pp = nullptr) :p{pp} { }
	T* get() const { return p; }
};

#endif /* LIST2_H_ */
