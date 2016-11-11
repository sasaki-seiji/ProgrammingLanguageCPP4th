/*
 * Matrix_body.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_BODY_H_
#define MATRIX_BODY_H_


#if 0
using Matrix_impl::Matrix_initializer;
#else
template<typename T, size_t N>
using Matrix_initializer = typename Matrix_impl::Matrix_init<T,N>::type;
#endif

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
	Matrix& operator=(const Matrix&) = default;
	~Matrix() = default;

	template<typename U>
		Matrix(const Matrix_ref<U,N>&);
	template<typename U>
		Matrix& operator=(const Matrix_ref<U,N>&);

	template<typename... Exts>
		explicit Matrix(Exts... exts);

	Matrix(Matrix_initializer<T,N>);
	Matrix& operator=(Matrix_initializer<T,N>);

#if 0 // 2016.11.06
	// error: use of deleted function 'Matrix<T, N>::Matrix(std::initializer_list<U>) [with U = int; T = double; long long unsigned int N = 0ull]'
	template<typename U>
		Matrix(std::initializer_list<U>) = delete;
	template<typename U>
		Matrix& operator=(std::initializer_list<U>) = delete;
#endif

	size_t extent(size_t n) const { return desc.extents[n]; }
	size_t size() const { return elems.size(); }
	const Matrix_slice<N>& descriptor() const { return desc; }
	size_t rows() const { return extent(0); }
	size_t cols() const { return extent(1); }

	T* data() { return elems.data(); }
	const T* data() const { return elems.data(); }

	template<typename... Args>
		Enable_if<Matrix_impl::Request_element<Args...>(), T&>
		operator()(Args... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Request_element<Args...>(), const T&>
		operator()(Args... args) const;

	template<typename... Args>
		Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<T,N>>
		operator()(const Args&... args);
	template<typename... Args>
		Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<const T,N>>
		operator()(const Args&... args) const;

#if 0	// 2016.11.05
	Matrix_ref<T,N-1> operator[](size_t i) { return row(i); }
	Matrix_ref<const T,N-1> operator[](size_t i) const { return row(i); }
#else
	template<size_t M=N>
		Enable_if<(M>1),Matrix_ref<T,N-1>>
		operator[](size_t i) { return row(i); }
	template<size_t M=N>
		Enable_if<(M==1),T&>
		operator[](size_t i) { return row(i); }
	template<size_t M=N>
		Enable_if<(M>1),Matrix_ref<const T,N-1>>
		operator[](size_t i) const { return row(i); }
	template<size_t M=N>
		Enable_if<(M==1),const T&>
		operator[](size_t i) const { return row(i); }
#endif

#if 0	// 2016.11.05
	Matrix_ref<T,N-1> row(size_t n);
	Matrix_ref<const T,N-1> row(size_t n) const;
#else
	template<size_t M = N>
		Enable_if<(M>1), Matrix_ref<T,M-1>> row(size_t n);
	template<size_t M = N>
		Enable_if<(M==1), T&> row(size_t n);
	template<size_t M = N>
		Enable_if<(M>1), Matrix_ref<const T,M-1>> row(size_t n) const;
	template<size_t M = N>
		Enable_if<(M==1), const T&> row(size_t n) const;
#endif

	Matrix_ref<T,N-1> col(size_t n);
	Matrix_ref<const T,N-1> col(size_t n) const;

	template<typename F>
		Matrix& apply(F f);

	template<typename M, typename F>
		Enable_if<Matrix_type<M>(),Matrix&> apply(const M& m, F f);

	Matrix& operator=(const T& value);
	Matrix& operator+=(const T& value);
	Matrix& operator-=(const T& value);
	Matrix& operator*=(const T& value);
	Matrix& operator/=(const T& value);
	Matrix& operator%=(const T& value);

	template<typename M>
		Enable_if<Matrix_type<M>(),Matrix&> operator+=(const M& m);
	template<typename M>
		Enable_if<Matrix_type<M>(),Matrix&> operator-=(const M& m);

	// 2016.11.05 add: get iterator

	iterator begin() { return elems.begin(); }
	const_iterator begin() const { return elems.begin(); }
	iterator end() { return elems.end(); }
	const_iterator end() const { return elems.end(); }

private:
	Matrix_slice<N> desc;
	std::vector<T> elems;
};

template<typename T>
class Matrix<T,0>
{
public:
	static constexpr size_t order = 0;
	using value_type = T;

	Matrix(const T& x) : elem(x) { }
	Matrix& operator=(const T& value) { elem = value; return *this; }

	T& operator()() { return elem; }
	const T& operator()() const { return elem; }

	operator T&() { return elem; }
	operator const T&() { return elem; }
private:
	T elem;
};

#endif

