/*
 * Matrix_ref_impl.h
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */

#ifndef MATRIX_REF_IMPL_H_
#define MATRIX_REF_IMPL_H_

#include "Matrix_ref_desc.h"


template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::row(size_t n)
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,ptr};
}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix_ref<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,ptr};
}

template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::col(size_t n)
{

}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix_ref<T,N>::col(size_t n) const
{

}


#endif /* MATRIX_REF_IMPL_H_ */
