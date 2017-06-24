/*
 * List.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_


template<typename T>
struct List {
	T val;
	List* succ;
};

template<typename T>
List<T>* begin(List<T>& l) { return &l; }

template<typename T>
List<T>* end(List<T>& l) { return nullptr;}

#endif /* LIST_H_ */
