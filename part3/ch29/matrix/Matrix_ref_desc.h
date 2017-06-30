/*
 * Matrix_ref.h
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */

#ifndef MATRIX_REF_DESC_H_
#define MATRIX_REF_DESC_H_

template<typename T, size_t N>
class Matrix_ref {
public:
	static constexpr size_t order = N;
	using value_type = T;

	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} {}

	Matrix_ref<T,N-1> operator[](size_t i) { return row(i); }
	Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }

	Matrix_ref<T,N-1> row(size_t n);
	Matrix_ref<const T,N-1> row(size_t n) const;

	Matrix_ref<T,N-1> col(size_t n);
	Matrix_ref<const T,N-1> col(size_t n) const;

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const{ return desc.size; }
	size_t rows() const { return desc.extents[0]; }

private:
	Matrix_slice<N> desc;
	T* ptr;
};


template<typename T>
class Matrix_ref<T,0> {
public:
	static constexpr size_t order = 0;
	using value_type = T;

	Matrix_ref(const Matrix_slice<0>& s, T* p) :ptr{p + s.start} {}

	T& operator()() { return *ptr; };
	const T& operator()() const { return *ptr; }

	operator T&() { return *ptr; }
	operator const T&() const { return *ptr; }

private:
	T* ptr;
};


#endif /* MATRIX_REF_DESC_H_ */
