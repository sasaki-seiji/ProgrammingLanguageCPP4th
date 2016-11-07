/*
 * Matrix.h
 *
 *  Created on: 2016/10/30
 *      Author: sasaki
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Matrix_concept.h"
#include "Matrix_etc.h"
#include "Matrix_impl.h"
#if 0
using Matrix_impl::Matrix_initializer;
#else
template<typename T, size_t N>
using Matrix_initializer = typename Matrix_impl::Matrix_init<T,N>::type;
#endif

#include "concept.h"
using namespace Estd;

#include <vector>
#include <initializer_list>
#include <numeric>
using std::size_t;

template<typename T, size_t N>
class Matrix_ref;


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

	// 2016.11.05 add
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

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

template<typename T, size_t N>
class Matrix_ref {
public:
	Matrix_ref(const Matrix_slice<N>& s, T* p) :desc{s}, ptr{p} { }
private:
	Matrix_slice<N> desc;
	T* ptr;
};

template<typename T, size_t N>
	template<typename... Exts>
	Matrix<T,N>::Matrix(Exts... exts)
//		:desc{exts...}, elems(desc.size)
		:desc(exts...), elems(desc.size)
	{ }

template<typename T, size_t N>
Matrix<T,N>::Matrix(Matrix_initializer<T,N> init)
{
	// 2016.11.06 add
	desc.start = 0;

	// 2016.11.06 change
#if 0
	desc.extents = Matrix_impl::derive_extents(init);
#else
	desc.extents = Matrix_impl::derive_extents<N>(init);
#endif
	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);
}

template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>::Matrix(const Matrix_ref<U,N>& x)
		:desc{x.desc}, elems{x.begin(),x.end()}
	{
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");
	}

template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix_ref<U,N>& x)
	{
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");

		desc = x.desc;
		elems.assign(x.begin(),x.end());
		return *this;
	}

template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator+=(const T& val)
{
	return apply([&](T& a){ a+=val; });
}

template<typename T, size_t N>
	template<typename F>
	Matrix<T,N>& Matrix<T,N>::apply(F f)
	{
		for (auto& x : elems) f(x);
		return *this;
	}

template<typename T,size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res+=val;
	return res;
}

template<typename T, size_t N>
	template<typename M>
	Enable_if<Matrix_type<M>(),Matrix<T,N>&> Matrix<T,N>::operator+=(const M& m)
	{
		static_assert(m.order==N,"+=: mismatched Matrix dimensions");
		assert(same_extents(desc,m.descriptor()));

		return apply(m, [](T& a, const Value_type<M>& b){ a+=b; });
	}

template<typename T, size_t N>
	template<typename M, typename F>
	Enable_if<Matrix_type<M>(),Matrix<T,N>&> Matrix<T,N>::apply(const M& m, F f)
	{
		assert(same_extents(desc,m.descriptor()));
		for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
			f(*i,*j);
		return *this;
	}

template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& a, const Matrix<T,N>& b)
{
	Matrix<T,N> res = a;
	res+=b;
	return res;
}

template<typename T, typename T2, size_t N,
	typename RT = Matrix<Common_type<Value_type<T>,Value_type<T2>>,N>>
Matrix<RT,N> operator+(const Matrix<T,N>& a, const Matrix<T2,N>& b)
{
	Matrix<RT,N> res = a;
	res+=b;
	return res;
}

template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix_ref<T,N>& x, const T& n)
{
	Matrix<T,N> res = x;
	res+=n;
	return res;
}

template<typename T>
Matrix<T,2> operator*(const Matrix<T,1>& u, const Matrix<T,1>& v)
{
	const size_t n = u.extent(0);
	const size_t m = v.extent(0);
	Matrix<T,2> res(n,m);
	for (size_t i = 0; i!=n; ++i)
		for (size_t j = 0; j!=m; ++j)
			res(i,j) = u[i]*v[j];
	return res;
}

template<typename T>
Matrix<T,1> operator*(const Matrix<T,2>& m, const Matrix<T,1>& v)
{
	assert(m.extent(1)==v.extent(0));
	const size_t nr = m.extent(0);
	const size_t nc = m.extent(1);
	Matrix<T,1> res(nr);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=nc; ++j)
			res(i,j) += m(i,j)*v(j);
	return res;
}

#if 0
template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2)
{
	const size_t nr = m1.extent(0);
	const size_t nc = m1.extent(1);
	assert(nc==m2.extent(0));
	const size_t p = m2.extent(1);
	Matrix<T,2> res(nr,p);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=p; ++j)
			for (size_t k = 0; k!=nc; ++k)
				res(i,j) += m1(i,k)*m2(k,j);
	return res;
}
#endif

template<typename T>
T dot_product(const Matrix<T,1>& a, const Matrix<T,1>& b)
{
	return std::inner_product(a.begin(),a.end(),b.begin(),0.0);
}

template<typename T>
Matrix<T,2> operator*(const Matrix<T,2>& m1, const Matrix<T,2>& m2)
{
	const size_t nr = m1.extent(0);
	const size_t nc = m1.extent(1);
	assert(nc==m2.extent(0));
	const size_t p = m2.extent(1);
	Matrix<T,2> res(nr,p);
	for (size_t i = 0; i!=nr; ++i)
		for (size_t j = 0; j!=p; ++j)
			res(i,j) = dot_product(m1[i],m2.col(j));
	return res;
}

#if 0

template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::row(size_t n)
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

template<typename T>
T& Matrix<T,1>::row(size_t i)
{
	return elem[i];
}

#else

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M>1),Matrix_ref<T,M-1>> Matrix<T,N>::row(size_t n)
	{
		assert(n<rows());
		Matrix_slice<N-1> row;
		Matrix_impl::slice_dim<0>(n,desc,row);
		return {row,data()};
	}

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M==1),T&> Matrix<T,N>::row(size_t i)
	{
		return elems[i];
	}

#endif

#if 0

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

template<typename T>
const T& Matrix<T,1>::row(size_t i) const
{
	return elem[i];
}

#else

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M>1),Matrix_ref<const T,M-1>>
	Matrix<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M==1),const T&>
	Matrix<T,N>::row(size_t i) const
{
	return elems[i];
}

#endif

template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::col(size_t n)
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), T&>
	Matrix<T,N>::operator()(Args... args)
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(data() + desc(args...));
	}

template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), const T&>
	Matrix<T,N>::operator()(Args... args) const
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(data() + desc(args...));
	}

template<typename T,size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<T,N>>
	Matrix<T,N>::operator()(const Args&... args)
	{
		Matrix_slice<N> d;
		d.start = Matrix_impl::do_slice(desc,d,args...);
		return {d,data()};
	}

template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<const T,N>>
	Matrix<T,N>::operator()(const Args&... args) const
	{
		Matrix_slice<N> d;
		d.start = Matrix_impl::do_slice(desc,d,args...);
		return {d,data()};
	}


#endif /* MATRIX_H_ */
