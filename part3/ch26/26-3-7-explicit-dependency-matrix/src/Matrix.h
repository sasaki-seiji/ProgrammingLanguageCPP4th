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
#include <cassert>

template<typename T>
class Matrix_base {
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
		//return elem;
			// error: ‘elem’ was not declared in this scope
		return this->elem;
	}
	int size() const
	{
		//return sz;
			// error: ‘sz’ was not declared in this scope
		return this->sz;
	}

	Matrix(std::initializer_list<int> il)
	{
		assert(il.size() == N);

		int s = 1, i = 0;
		for ( auto x : il ) {
			s *= x;
			dim[i++] = x;
		}
		this->alloc(s);
	}
};

#endif /* MATRIX_H_ */
