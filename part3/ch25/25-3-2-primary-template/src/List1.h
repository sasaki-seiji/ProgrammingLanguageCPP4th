/*
 * List1.h
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */

#ifndef LIST1_H_
#define LIST1_H_

#include "regular.h"
using namespace Estd;

#include <list>

//template<typename T> class List1<T*> { };
	// error: ‘List1’ is not a class template

template<typename T>
class List1 {
	static_assert(Regular<T>(), "List1(): T must be Regular");

	std::list<T> lst;
public:
	List1(std::initializer_list<T> il) :lst{il} {}
	std::size_t size() const { return lst.size(); }
};

template<typename T>
class List1<T*> {
	std::list<T*> lst;
public:
	List1(std::initializer_list<T*> il) :lst{il} { }
	std::size_t size() const { return lst.size(); }
};


#endif /* LIST1_H_ */
