/*
 * Matrix.h
 *
 *  Created on: 2016/09/25
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <array>
#include <initializer_list>

template<typename T>
class Matrix_base {
public:
	int size() const { return sz; }
protected:
	int sz;
	T* elem;

	void alloc(int s) { sz = s; elem = new T[s]; }
};

template<typename T, int N>
class Matrix : public Matrix_base<T> {
	std::array<int,N> dim;
public:
	T* data()
	{
		return this->elem;
	}

	Matrix(std::initializer_list<int> il)
	{
		int s = 1;
		int i = 0;
		auto it = il.begin();
		for ( ; i < N && it!=il.end(); ++i, ++it ) {
			s *= *it;
			dim[i] = *it;
		}
		this->alloc(s);
	}
};

#endif /* MATRIX_H_ */
