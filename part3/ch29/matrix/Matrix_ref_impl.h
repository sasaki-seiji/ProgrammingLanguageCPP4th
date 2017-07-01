/*
 * Matrix_ref_impl.h
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */

#ifndef MATRIX_REF_IMPL_H_
#define MATRIX_REF_IMPL_H_

#include "Matrix_ref_desc.h"

// Matrix_ref_iterator

template<typename T, size_t N>
Matrix_ref_iterator<T,N> Matrix_ref_iterator<T,N>::begin(const Matrix_ref<T,N>* t)
{
	Matrix_ref_iterator<T,N> iter{t};
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N> Matrix_ref_iterator<T,N>::end(const Matrix_ref<T,N>* t)
{
	Matrix_ref_iterator<T,N> iter{t, true};
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N>& Matrix_ref_iterator<T,N>::operator++()
{
	for (int i = N-1; i >= 0; --i) {
		if (++pos[i] < target->descriptor().extents[i]) return *this;
		pos[i] = 0;
	}
	ov = true;
	return *this;
}

template<typename T, size_t N>
ostream& operator<<(ostream& os, const Matrix_ref_iterator<T,N>& iter)
{
	os << "target: " << *iter.target << ", pos: " << iter.pos
			<< ", ov: " << iter.ov << endl;
	return os;
}

// row
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,ptr};
}

// col
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,ptr};
}

#endif /* MATRIX_REF_IMPL_H_ */
