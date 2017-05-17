/*
 * Smart_pointer.h
 *
 *  Created on: 2017/05/17
 *      Author: sasaki
 */

#ifndef SMART_POINTER_H_
#define SMART_POINTER_H_

#include <type_traits>

template<bool B, typename T =void>
using Enable_if = typename std::enable_if<B,T>::type;

template<typename T>
constexpr bool Is_class()
{
	return std::is_class<T>::value;
}

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
		//Enable_if<Is_class<T>(),T>* operator->() { return p; }
		Enable_if<Is_class<U>(),U>* operator->() { return p; }
			//error: no type named 'type' in 'struct std::enable_if<false, double>'
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
