/*
 * Vec.h
 *
 *  Created on: 2016/04/02
 *      Author: sasaki
 */

#ifndef VEC_H_
#define VEC_H_

#include <vector>

template<typename T>
class Vec : public std::vector<T> {
public:
	using std::vector<T>::vector;

	T& operator[](int i) { return std::vector<T>::at(i); }
	const T& operator[](int i) const { return std::vector<T>::at(i); }
};

#endif /* VEC_H_ */
