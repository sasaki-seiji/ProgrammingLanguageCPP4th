/*
 * Matrix_ref.h
 *
 *  Created on: 2017/06/30
 *      Author: sasaki
 */

#ifndef MATRIX_REF_DESC_H_
#define MATRIX_REF_DESC_H_

// iterator for Matrix_ref

template<typename T, size_t N>
ostream& operator<<(ostream& os, const Matrix_ref_iterator<T,N>& iter);

template<typename T, size_t N>
class Matrix_ref_iterator : public iterator<forward_iterator_tag, T> {
public:
	static Matrix_ref_iterator begin(const Matrix_ref<T,N>* t);
	static Matrix_ref_iterator end(const Matrix_ref<T,N>* t);

	Matrix_ref_iterator& operator++();
	T& operator*()
		{ return *(target->data() + target->descriptor().offset(pos)); }
	bool operator!=(const Matrix_ref_iterator& o)
		{ return !(pos == o.pos && ov == o.ov); }

private:
	Matrix_ref_iterator(const Matrix_ref<T,N>* t, bool ov = false)
		: target{t}, ov{ov} { fill(pos.begin(), pos.end(), 0); }

	const Matrix_ref<T,N> *target;
	array<size_t, N> pos;
	bool ov;

	template<typename U, size_t NN>
	friend ostream& operator<<(ostream& os, const Matrix_ref_iterator<U,NN>& iter);
};

// primary template for Matrix_ref

template<typename T, size_t N>
class Matrix_ref {
public:
	static constexpr size_t order = N;
	using value_type = T;
	using iterator = Matrix_ref_iterator<T,N>;

	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} {}
	Matrix_ref& operator=(Matrix_initializer<T,N> init);

	template<typename... Args>
		Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
		operator()(Args... args) const;

	Matrix_ref<T,N-1> operator[](size_t i) const { return row(i); }
	Matrix_ref<T,N-1> row(size_t n) const;
	Matrix_ref<T,N-1> col(size_t n) const;

	template<typename F>
		Matrix_ref& apply(F f);
	Matrix_ref& operator=(const T& value);

	template<template<typename,size_t> class M, typename T2, typename F,
		typename =Enable_if<Dimensional_Matrix_type<M,T2,N>()>>
	Matrix_ref& apply(const M<T2,N>& m, F f);

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const{ return desc.size; }
	size_t rows() const { return desc.extents[0]; }
	size_t cols() const { return desc.extents[1]; }
	const Matrix_slice<N>& descriptor() const { return desc; }

	T* data() const { return ptr; }

	iterator begin() const { return Matrix_ref_iterator<T,N>::begin(this); }
	iterator end() const { return Matrix_ref_iterator<T,N>::end(this); }

private:
	Matrix_slice<N> desc;
	T* ptr;
};

template<typename T>
T dot_product(const Matrix_ref<T,1>& a, const Matrix_ref<T,1>& b);


// specialized template for Matrix_ref<T,0>

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
