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

template<typename... Args>
constexpr bool All(bool b, Args... args);

template<typename... Args>
constexpr bool Some(bool b, Args... args);

template<size_t N>
std::ostream& operator<<(std::ostream& os, const Matrix_slice<N>& ms);

template<typename M>
Enable_if<Matrix_type<M>(),std::ostream&>
operator<<(std::ostream& os, const M& m);

template<size_t N>
bool same_extents(const Matrix_slice<N>&, const Matrix_slice<N>&);


// declare of Matrix_impl

namespace Matrix_impl {

	template<typename T, size_t N> struct Matrix_init;

	template<size_t N, typename List>
	std::array<size_t,N> derive_extents(const List& list);

	template<size_t N, typename I, typename List>
	Enable_if<(N>1),void> add_extents(I& first, const List& list);

	template<size_t N, typename I, typename List>
	Enable_if<(N==1),void> add_extents(I& first, const List& list);

	template<size_t N, typename List> bool check_non_jagged(const List& list);

	template<size_t N> void compute_strides(Matrix_slice<N>& ms) ;

	template<typename T, typename Vec>
	void add_list(const std::initializer_list<T>* first,
			const std::initializer_list<T>* last, Vec& vec);

	template<typename T, typename Vec>
	void add_list(const T* first, const T* last, Vec& vec);

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

	// 2016.11.10 add

	template<typename Val, typename Iter>
	void copy_flat(const Val& v, Iter& it);

	template<typename T, typename Iter>
	void copy_flat(std::initializer_list<T> init, Iter& it);

}


#endif /* MATRIX_DECL_H_ */
