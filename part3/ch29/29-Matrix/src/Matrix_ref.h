/*
 * Matrix_ref.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_REF_H_
#define MATRIX_REF_H_


template<typename T, size_t N>
class Matrix_ref {
public:
	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} { }
private:
	Matrix_slice<N> desc;
	T* ptr;
};

template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix_ref<T,N>& x, const T& n)
{
	Matrix<T,N> res = x;
	res+=n;
	return res;
}




#endif /* MATRIX_REF_H_ */
