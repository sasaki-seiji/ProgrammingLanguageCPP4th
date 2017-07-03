/*
 * Matrix_impl.h
 *
 *  Created on: 2017/06/25
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_H_
#define MATRIX_IMPL_H_

#include "Matrix_concept.h"
#include "slice.h"
#include "Matrix_decl.h"
#include "Matrix_impl_impl.h"

// print Matrix, Matrix_ref
template<typename M>
	Enable_if<Matrix_type<M>(), ostream&>
operator<<(ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=m.rows(); ++i) {
		os << m[i];
		if (i+1!=m.rows()) os << ',';
	}
	return os << '}';
}

// construct from extents
template<typename T, size_t N>
template<typename... Exts>
Matrix<T,N>::Matrix(Exts... exts)
	:desc{exts...}, elems(desc.size)
{
}

// construct from Matrix_initializer
template<typename T, size_t N>
Matrix<T,N>::Matrix(Matrix_initializer<T,N> init)
{
	desc.extents = Matrix_impl::derive_extents<N>(init);

	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);
}

// row
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::row(size_t n)
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

// col
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

// fortran style index access
template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_element<Args...>(), T&>
	Matrix<T,N>::operator()(Args... args)
{
	static_assert(sizeof...(Args)==N,
			"Matrix<T,N>::operator()(size_t...): dimension mismatch");

	assert(Matrix_impl::check_bounds(desc, args...));
	return *(data() + desc(args...));
}

template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_element<Args...>(), const T&>
	Matrix<T,N>::operator()(Args... args) const
{
	assert(Matrix_impl::check_bounds(desc, args...));
	return *(data() + desc(args...));
}

// m(slice...)
template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<T,N>>
	Matrix<T,N>::operator()(const Args... args)
{
	Matrix_slice<N> d;
	d.start = Matrix_impl::do_slice(desc, d, args...);
	return {d, data()};
}

template<typename T, size_t N>
template<typename... Args>
	Enable_if<Matrix_impl::Requesting_slice<Args...>(), Matrix_ref<const T,N>>
	Matrix<T,N>::operator()(const Args... args) const
{
	Matrix_slice<N> d;
	d.start = Matrix_impl::do_slice(desc, d, args...);
	return {d, data()};
}

// construct from Matrix_ref
template<typename T, size_t N>
template<typename U>
	Matrix<T,N>::Matrix(const Matrix_ref<U,N>& x)
		:desc{x.descriptor().extents}, elems{x.begin(),x.end()}
{
	static_assert(Convertible<U,T>(),
			"Matrix constructor: incompatible element types");
}

// assign from Matrix_ref
template<typename T, size_t N>
template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix_ref<U,N>& x)
{
	static_assert(Convertible<U,T>(),
			"Matrix =: incompatible element types");

	desc = x.descriptor().extents;
	elems.assign(x.begin(), x.end());
	return *this;
}

// scalar operator

template<typename T, size_t N>
template<typename F>
Matrix<T,N>& Matrix<T,N>::apply(F f)
{
	for (auto& x : elems) f(x);
	return *this;
}

template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator=(const T& val)
{

}
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator+=(const T& val)
{
	return apply([&](T& a) { a+= val; });
}
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator-=(const T& val)
{
	return apply([&](T& a) { a-= val; });
}
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator*=(const T& val)
{
	return apply([&](T& a) { a*= val; });
}
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator/=(const T& val)
{
	return apply([&](T& a) { a/= val; });
}
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator%=(const T& val)
{
	return apply([&](T& a) { a%= val; });
}

// matrix and scalar

template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res += val;
	return res;
}

template<typename T, size_t N>
Matrix<T,N> operator-(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res -= val;
	return res;
}

template<typename T, size_t N>
Matrix<T,N> operator*(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res *= val;
	return res;
}

template<typename T, size_t N>
Matrix<T,N> operator/(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res /= val;
	return res;
}

template<typename T, size_t N>
Matrix<T,N> operator%(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res %= val;
	return res;
}

// matrix += matrix

template<typename T, size_t N>
template<typename M>
Enable_if<Matrix_type<M>(), Matrix<T,N>&> Matrix<T,N>::operator+=(const M& m)
{
	static_assert(m.order==N, "+=: mismatched Matrix dimensions");
	assert(same_extents(desc, m.descriptor()));

	return apply(m, [](T& a, const Value_type<M>& b){ a += b; });
}


// apply function to *this and matrix
template<typename T, size_t N>
template<typename M, typename F>
Enable_if<Matrix_type<M>(), Matrix<T,N>&> Matrix<T,N>::apply(const M& m, F f)
{
	assert(same_extents(desc, m.descriptor()));
	for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
		f(*i,*j);
	return *this;
}


// matrix -= matrix
template<typename T, size_t N>
template<typename M>
Enable_if<Matrix_type<M>(), Matrix<T,N>&> Matrix<T,N>::operator-=(const M& m)
{
	static_assert(m.order==N, "-=: mismatched Matrix dimensions");
	assert(same_extents(desc, m.descriptor()));

	return apply(m, [](T& a, const Value_type<M>& b){ a -= b; });
}

#endif /* MATRIX_IMPL_H_ */
