/*
 * Matrix_decl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_DECL_H_
#define MATRIX_DECL_H_

#include "type_converter.h"
using namespace Estd;

#include "fwd_decl.h"
#include "Matrix_concept.h"
#include "Matrix_slice.h"

#include <vector>
#include <iostream>
using namespace std;

template<typename T, size_t N>
class Matrix {
public:
	static constexpr size_t order = N;
	using value_type = T;
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	Matrix() = default;
	Matrix(Matrix&&) = default;
	Matrix& operator=(Matrix&&) = default;
	Matrix(const Matrix&) = default;
	Matrix& operator=(Matrix&) = default;
	~Matrix() = default;

	template<typename U>
		Matrix(const Matrix_ref<U,N>&);
	template<typename U>
		Matrix& operator=(const Matrix_ref<U,N>&);

	template<typename... Exts>
		explicit Matrix(Exts... exts);

	Matrix(Matrix_initializer<T,N>);
	Matrix& operator=(Matrix_initializer<T,N>);

	template<typename U, size_t NN=N, typename =Enable_if<(NN>1)>>
		Matrix(initializer_list<U>) = delete;
	template<typename U, size_t NN=N, typename =Enable_if<(NN>1)>>
		Matrix& operator=(initializer_list<U>) = delete;

	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
		operator()(Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
		operator()(Args... args) const;

	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
		operator()(const Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
		operator()(const Args... args) const;

	Matrix_ref<T,N-1> operator[](size_t i) { return row(i); }
	Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }

	Matrix_ref<T,N-1> row(size_t n);
	Matrix_ref<const T,N-1> row(size_t n) const;

	Matrix_ref<T,N-1> col(size_t n);
	Matrix_ref<const T,N-1> col(size_t n) const;

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const{ return elems.size(); }
	size_t rows() const { return desc.extents[0]; }
	size_t cols() const { return desc.extents[1]; }

	const Matrix_slice<N>& descriptor() const { return desc; }

	T* data() { return elems.data(); }
	const T* data() const { return elems.data(); }

private:
	Matrix_slice<N> desc;
	vector<T> elems;
};


#endif /* MATRIX_DECL_H_ */
