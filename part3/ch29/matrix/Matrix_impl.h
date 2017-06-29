/*
 * Matrix_impl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_H_
#define MATRIX_IMPL_H_

#include "Matrix_decl.h"
#include "Matrix_impl_impl.h"

template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=rows(m); ++i) {
		os << m[i];
		if (i+1!=rows(m)) os << ',';
	}
	return os << '}';
}

template<typename T, size_t N>
template<typename... Exts>
Matrix<T,N>::Matrix(Exts... exts)
	:desc{exts...}, elems(desc.size)
{
}

template<typename T, size_t N>
Matrix<T,N>::Matrix(Matrix_initializer<T,N> init)
{
	desc.extents = Matrix_impl::derive_extents<N>(init);

	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);
}


#endif /* MATRIX_IMPL_H_ */
