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

}


#endif /* MATRIX_DECL_H_ */
