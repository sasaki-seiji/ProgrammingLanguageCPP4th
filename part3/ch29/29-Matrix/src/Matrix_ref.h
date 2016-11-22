/*
 * Matrix_ref.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_REF_H_
#define MATRIX_REF_H_

// 2016.11.09 add
// iterator for Matrix_ref
template<typename T, size_t N>
class Matrix_ref_iterator : public std::iterator<std::input_iterator_tag, T>
{
public:
	bool operator==(const Matrix_ref_iterator& other) const ;
	bool operator!=(const Matrix_ref_iterator& other) const
		{ return !(*this == other); }
	Matrix_ref_iterator& operator++();
	T& operator*();

	static Matrix_ref_iterator begin(Matrix_ref<T,N>* ref);
	static Matrix_ref_iterator end(Matrix_ref<T,N>* ref);

private:
	Matrix_ref_iterator(Matrix_ref<T,N>* ref);

	Matrix_ref<T,N> *ref;
	std::array<size_t, N> cur;
};

// 2016.11.09 add
// const iterator for Matrix_ref
template<typename T, size_t N>
class Matrix_ref_const_iterator : public std::iterator<std::input_iterator_tag, T>
{
public:
	bool operator==(const Matrix_ref_const_iterator& other) const ;
	bool operator!=(const Matrix_ref_const_iterator& other) const
		{ return !(*this == other); }
	Matrix_ref_const_iterator& operator++();
	const T& operator*();

	static Matrix_ref_const_iterator begin(const Matrix_ref<T,N>* ref);
	static Matrix_ref_const_iterator end(const Matrix_ref<T,N>* ref);

private:
	Matrix_ref_const_iterator(const Matrix_ref<T,N>* ref);

	const Matrix_ref<T,N> *ref;
	std::array<size_t, N> cur;
};

// Matrix_ref class: refer part of Matrix

template<typename T, size_t N>
class Matrix_ref {
public:

	// 2016.11.08 add

	static constexpr size_t order = N;
	using value_type = T;
	using iterator = Matrix_ref_iterator<T,N>;
	using const_iterator = Matrix_ref_const_iterator<T,N>;


	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} { }

	// 2016.11.10 add
	Matrix_ref& operator=(Matrix_initializer<T,N>);

	// fortran style index access
	template<typename... Args>
		Enable_if<Matrix_impl::Request_element<Args...>(), T&>
		operator()(Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Request_element<Args...>(), const T&>
		operator()(Args... args) const;

	// slice access
	template<typename... Args>
		Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<T,N>>
		operator()(const Args&... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<const T,N>>
		operator()(const Args&... args) const;


	// 2016.11.08 add: index, row, col
	// 2016.11.21 change

	Matrix_ref<T,N-1> operator[](size_t i) { return row(i); }
	Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }

	Matrix_ref<T,N-1> row(size_t n);
	Matrix_ref<const T,N-1> row(size_t n) const;

	Matrix_ref<T,N-1> col(size_t n);
	Matrix_ref<const T,N-1> col(size_t n) const;


	template<typename F>
		Matrix_ref& apply(F f);

	template<typename M, typename F>
		Enable_if<Matrix_type<M>(),Matrix_ref&> apply(const M& m, F f);

	Matrix_ref& operator=(const T& value);
	Matrix_ref& operator+=(const T& value);
	Matrix_ref& operator-=(const T& value);
	Matrix_ref& operator*=(const T& value);
	Matrix_ref& operator/=(const T& value);
	Matrix_ref& operator%=(const T& value);

	template<typename M>
		Enable_if<Matrix_type<M>(),Matrix_ref&> operator+=(const M& m);
	template<typename M>
		Enable_if<Matrix_type<M>(),Matrix_ref&> operator-=(const M& m);


	// 2016.11.08 add: metrics

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const { return desc.size; }
	const Matrix_slice<N>& descriptor() const { return desc; }
	size_t rows() const { return extent(0); }
	size_t cols() const { return extent(1); }

	// 2016.11.08 add: get iterator

	iterator begin() { return iterator::begin(this); }
	const_iterator begin() const { return const_iterator::begin(this); }
	iterator end() { return iterator::end(this); }
	const_iterator end() const { return const_iterator::end(this); }

	// 2016.11.09 add: access element

	T& at(std::array<size_t,N>& i) { return *(ptr + desc.at(i)); }
	const T& at(std::array<size_t,N>& i) const 	{ return *(ptr + desc.at(i)); }

private:
	Matrix_slice<N> desc;
	T* ptr;
};


// Matrix_ref<T,N> の　N=0 の時の特殊化
//	Matrix<T,1>::row(size_t),　Matrix_ref<T,1>::row(size_t)のリターン値となる
template<typename T>
class Matrix_ref<T,0>
{
public:
	static constexpr size_t order = 0;
	using value_type = T;

	Matrix_ref(const Matrix_slice<0>& s, T* p) :desc{s}, ptr{p} { }

	T& operator()() { return *(ptr + desc()); }
	const T& operator()() const { return *(ptr + desc()); }

	operator T&() { return *(ptr + desc()); }
	operator const T&() const { return *(ptr + desc()); }

	Matrix_ref& operator=(const T& v) { *(ptr + desc()) = v; return *this; }

private:
	Matrix_slice<0> desc;
	T* ptr;
};


#endif /* MATRIX_REF_H_ */
