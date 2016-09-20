/*
 * List1.h
 *
 *  Created on: 2016/09/20
 *      Author: sasaki
 */

#ifndef LIST1_H_
#define LIST1_H_



//template<typename T>
//class List1<T> {
//};
// error: 'List1' is not a class template

template<typename T>
class List1 {
	T val;
public:
	List1(const T& v = T{}) :val{v} {}
	T get() const { return val; }
};

template<typename T>
class List1<T*> {
	T*	p;
public:
	List1(T* pp = nullptr) :p{pp} { }
	T* get() const { return p; }
};


#endif /* LIST1_H_ */
