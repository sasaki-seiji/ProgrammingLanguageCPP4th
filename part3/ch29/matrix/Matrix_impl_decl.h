/*
 * Matrix_impl_decl.h
 *
 *  Created on: 2017/06/26
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_DECL_H_
#define MATRIX_IMPL_DECL_H_

#include <cstddef>
#include <array>

#include "type_converter.h"
using namespace Estd;

#include "fwd_decl.h"

namespace Matrix_impl {

	template<std::size_t N, typename List>
	std::array<std::size_t, N> derive_extents(const List& list);

	template<std::size_t N, typename I, typename List>
	Enable_if<(N>1),void> add_extents(I& first, const List& list);

	template<std::size_t N, typename I, typename List>
	Enable_if<(N==1),void> add_extents(I& first, const List& list);

	template<std::size_t N, typename List>
	bool check_non_jagged(const List& list);

	template<std::size_t N>
	void compute_strides(Matrix_slice<N>& ms);

	template<typename T, typename Vec>
	void insert_flat(initializer_list<T> list, Vec& vec);

	template<typename T, typename Vec>
	void add_list(const initializer_list<T>* first, const initializer_list<T>* last,
			Vec& vec);

	template<typename T, typename Vec>
	void add_list(const T* first, const T* last, Vec& vec);

	template<size_t I, size_t N>
	void slice_dim(size_t offset, const Matrix_slice<N>& desc, Matrix_slice<N-1>& row);

	template<size_t N, typename... Dims>
	bool check_bounds(const Matrix_slice<N>& desc, Dims... dims);

} // end of Matrix_impl


#endif /* MATRIX_IMPL_DECL_H_ */
