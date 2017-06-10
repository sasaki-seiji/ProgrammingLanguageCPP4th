/*
 * List2.h
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */

#ifndef LIST2_H_
#define LIST2_H_

#include <list>

template<typename T>
class List2 ;

template<typename T>
class List2<T*> {
	std::list<T*>	lst;
public:
	List2(std::initializer_list<T*> il) :lst{il} { }
	std::size_t size() const { return lst.size(); }
};

#endif /* LIST2_H_ */
