/*
 * copy.h
 *
 *  Created on: 2017/05/25
 *      Author: sasaki
 */

#ifndef COPY_H_
#define COPY_H_

#include <type_traits>
#include <iostream>
#include <cstring>

template<typename T>
void copy(T* p, const T* q, int n)
{
	if (std::is_pod<T>::value) {
		std::cout << "copy() - is_pod\n";
		std::memcpy(p,q,n*sizeof(T));
	}
	else {
		std::cout << "copy() - not is_pod\n";
		for (int i=0; i!=n; ++i)
			p[i] = q[i];
	}
}

template<typename T>
void copy2(T* p, const T* q, int n)
{
	if (std::is_pod<T>()) {
		std::cout << "copy2() - is_pod\n";
		std::memcpy(p,q,n*sizeof(T));
	}
	else {
		std::cout << "copy2() - not is_pod\n";
		for (int i=0; i!=n; ++i)
			p[i] = q[i];
	}
}


#endif /* COPY_H_ */
