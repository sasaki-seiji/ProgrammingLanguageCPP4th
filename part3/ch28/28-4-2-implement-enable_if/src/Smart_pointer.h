/*
 * Smart_pointer.h
 *
 *  Created on: 2017/05/17
 *      Author: sasaki
 */

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include "my_enable_if.h"
#include "primary_type_predicate.h"
using namespace Estd;

template<typename T>
class Smart_pointer {
	T *p;
	int *pcounter;

	void add_ref();
	void release();

public:
	Smart_pointer(T* pp) : p{pp}, pcounter{new int{1}} { }
	Smart_pointer(const Smart_pointer& o);
	Smart_pointer& operator=(const Smart_pointer& o);
	~Smart_pointer() { release(); }

	T& operator*() { return *p; }
	template<typename U=T>
		My_enable_if<Is_class<U>(),U>* operator->() { return p; }
};

template<typename T>
void Smart_pointer<T>::add_ref()
{
	++*pcounter;
}

template<typename T>
void Smart_pointer<T>::release()
{
	if (--*pcounter == 0) {
		delete pcounter;
		delete p;
	}
}

template<typename T>
Smart_pointer<T>::Smart_pointer(const Smart_pointer& o)
	: p{o.p}, pcounter{o.pcounter}
{
	add_ref();
}

template<typename T>
Smart_pointer<T>& Smart_pointer<T>::operator=(const Smart_pointer& o)
{
	release();
	p = o.p;
	pcounter = o.pcounter;
	add_ref();
}



#endif /* SMART_POINTER_H_ */
