/*
 * Matrix_decl.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_DECL_H_
#define MATRIX_DECL_H_

// Matrix_body.h, Matrix_ref.h

template<typename T, size_t N> class Matrix ;
template<typename T, size_t N> class Matrix_ref;
template<typename T, size_t N> class Matrix_ref_iterator;
template<typename T, size_t N> class Matrix_ref_const_iterator;

// Matrix_util.h

struct slice ;
template<size_t N> struct Matrix_slice ;


// declare of Matrix_impl

namespace Matrix_impl {

	template<typename T, size_t N> struct Matrix_init;

	// used in Matrix_util.h
	template<size_t N> void compute_strides(Matrix_slice<N>& ms) ;

	template<size_t I, size_t N>
	void slice_dim(size_t n, const Matrix_slice<N>& os, Matrix_slice<N-1>& ns);

	template<size_t N, typename... Dims>
	bool check_bounds(const Matrix_slice<N>& slice, Dims... dims);

	template<typename... Args> constexpr bool Request_element();

	template<typename... Args> constexpr bool Request_slice();

	template<size_t I, size_t N>
	size_t do_slice_dim(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
			size_t n) ;

	template<size_t I, size_t N>
	size_t do_slice_dim(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
			const slice& s);

	template<size_t N, typename T, typename... Args>
	size_t do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
			const T& s, const Args&... args);

	template<size_t N>
	size_t do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns);

}


#endif /* MATRIX_DECL_H_ */
