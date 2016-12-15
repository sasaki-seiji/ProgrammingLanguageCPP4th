/*
 * Matrix_body.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_BODY_IMPL_H_
#define MATRIX_BODY_IMPL_H_


// Matrix constructor from extents
template<typename T, size_t N>
	template<typename... Exts>
	Matrix<T,N>::Matrix(Exts... exts)
//		:desc{exts...}, elems(desc.size)
		:desc(exts...), elems(desc.size)
	{ }

// Matrix construct from Matrix_initializer
template<typename T, size_t N>
Matrix<T,N>::Matrix(Matrix_initializer<T,N> init)
{
	// 2016.11.06 add
	desc.start = 0;

	// 2016.11.06 change
	//desc.extents = Matrix_impl::derive_extents(init);
	desc.extents = Matrix_impl::derive_extents<N>(init);

	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);
}

// 2016.11.13: Matrix: assign Matrix_initializer
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator=(Matrix_initializer<T,N> init)
{
	elems.clear();	// not exception safe

	desc.start = 0;
	desc.extents = Matrix_impl::derive_extents<N>(init);
	Matrix_impl::compute_strides(desc);
	elems.reserve(desc.size);
	Matrix_impl::insert_flat(init,elems);
	assert(elems.size() == desc.size);

	return *this;
}

// Matrix construct from Matrix_ref
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>::Matrix(const Matrix_ref<U,N>& x)
// 2016.11.08, 2016.11.12 change
		//:desc{x.desc}, elems{x.begin(),x.end()}
		: elems(x.begin(),x.end())
	{
		static_assert(Is_convertible<U,T>(), "Matrix constructor: incompatible element types");

		// 2016.11.12 add
		desc.start = 0;
		desc.extents = x.descriptor().extents;
		Matrix_impl::compute_strides(desc);
	}

// Matrix: assign Matrix_ref
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix_ref<U,N>& x)
	{
		static_assert(Is_convertible<U,T>(), "Matrix constructor: incompatible element types");

		std::vector<T> nv{x.begin(), x.end()};	// exception safe

		desc.start = 0;
		desc.extents = x.descriptor().extents;
		Matrix_impl::compute_strides(desc);
		elems = nv;
		return *this;
	}

// 2016.11.11 add
// Matrix construct from other type Matrix
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>::Matrix(const Matrix<U,N>& x)
		:desc{x.descriptor()}, elems(x.begin(),x.end())
	{
		static_assert(Is_convertible<U,T>(), "Matrix constructor: incompatible element types");
	}

// 2016.11.13 add
// Matrix: assign other type Matrix
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix<U,N>& x)
	{
		static_assert(Is_convertible<U,T>(), "Matrix constructor: incompatible element types");

		std::vector<T> nv{x.begin(),x.end()};
		desc = x.descriptor();
		elems = nv;
	}


// Matrix = scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator=(const T& val)
{
	return apply([&](T& a){ a=val; });
}

// Matrix += scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator+=(const T& val)
{
	return apply([&](T& a){ a+=val; });
}

// Matrix -= scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator-=(const T& val)
{
	return apply([&](T& a){ a-=val; });
}

// 2016.11.11 add
// Matrix *= scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator*=(const T& val)
{
	return apply([&](T& a){ a*=val; });
}

// Matrix /= scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator/=(const T& val)
{
	return apply([&](T& a){ a/=val; });
}

// Matrix %= scalar
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator%=(const T& val)
{
	return apply([&](T& a){ a%=val; });
}

template<typename T, size_t N>
	template<typename F>
	Matrix<T,N>& Matrix<T,N>::apply(F f)
	{
		for (auto& x : elems) f(x);
		return *this;
	}

// Matrix + scalar
template<typename T,size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res+=val;
	return res;
}

// Matrix - scalar
template<typename T,size_t N>
Matrix<T,N> operator-(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res-=val;
	return res;
}

// Matrix * scalar
template<typename T,size_t N>
Matrix<T,N> operator*(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res*=val;
	return res;
}

// Matrix / scalar
template<typename T,size_t N>
Matrix<T,N> operator/(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res/=val;
	return res;
}

// Matrix % scalar
template<typename T,size_t N>
Matrix<T,N> operator%(const Matrix<T,N>& m, const T& val)
{
	Matrix<T,N> res = m;
	res%=val;
	return res;
}

// Matrix += Matrix_type
template<typename T, size_t N>
	template<typename M>
	Enable_if<Matrix_type<M>(),Matrix<T,N>&> Matrix<T,N>::operator+=(const M& m)
	{
		static_assert(m.order==N,"+=: mismatched Matrix dimensions");
		assert(same_extents(desc,m.descriptor()));

		return apply(m, [](T& a, const Value_type<M>& b){ a+=b; });
	}

// Matrix -= Matrix_type
template<typename T, size_t N>
	template<typename M>
	Enable_if<Matrix_type<M>(),Matrix<T,N>&> Matrix<T,N>::operator-=(const M& m)
	{
		static_assert(m.order==N,"-=: mismatched Matrix dimensions");
		assert(same_extents(desc,m.descriptor()));

		return apply(m, [](T& a, const Value_type<M>& b){ a-=b; });
	}

// Matrix::apply:
//	apply f between *this elements and Matrix_type elements
template<typename T, size_t N>
	template<typename M, typename F>
	Enable_if<Matrix_type<M>(),Matrix<T,N>&> Matrix<T,N>::apply(const M& m, F f)
	{
		assert(same_extents(desc,m.descriptor()));
		for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
			f(*i,*j);
		return *this;
	}

// Matrix + Matrix
template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& a, const Matrix<T,N>& b)
{
	Matrix<T,N> res = a;
	res+=b;
	return res;
}

// Matrix - Matrix
template<typename T, size_t N>
Matrix<T,N> operator-(const Matrix<T,N>& a, const Matrix<T,N>& b)
{
	Matrix<T,N> res = a;
	res-=b;
	return res;
}

// Matrix + Matrix_ref
template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix<T,N>& a, const Matrix_ref<T,N>& b)
{
	Matrix<T,N> res = a;
	res+=b;
	return res;
}

// Matrix - Matrix_ref
template<typename T, size_t N>
Matrix<T,N> operator-(const Matrix<T,N>& a, const Matrix_ref<T,N>& b)
{
	Matrix<T,N> res = a;
	res-=b;
	return res;
}

// 2016.11.11 change : RT
// Matrix<T1> + Matrix<T2>
template<typename T, typename T2, size_t N,
	//typename RT = Matrix<Common_type<Value_type<T>,Value_type<T2>>,N>>
	typename RT = Common_type<T,T2>>
Matrix<RT,N> operator+(const Matrix<T,N>& a, const Matrix<T2,N>& b)
{
	Matrix<RT,N> res = a;
	//Matrix<RT,N> res{a};
	res+=b;
	return res;
}

// Matrix<T1> - Matrix<T2>
template<typename T, typename T2, size_t N,
	typename RT = Common_type<T,T2>>
Matrix<RT,N> operator-(const Matrix<T,N>& a, const Matrix<T2,N>& b)
{
	Matrix<RT,N> res = a;
	res-=b;
	return res;
}

// Matrix<T,N>の行を参照するMatrix_ref<N-1,T>を返す
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::row(size_t n)
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

#if 0
template<typename T>
T& Matrix<T,1>::row(size_t i)
{
	return elem[i];
}
//error: invalid use of incomplete type 'class Matrix<T, 1ull>'
#endif


// const Matrix<T,N>の行を参照するMatrix_ref<const T, N-1>を返す
template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,data()};
}

#if 0
template<typename T>
const T& Matrix<T,1>::row(size_t i) const
{
	return elem[i];
}
// error: invalid use of incomplete type 'class Matrix<T, 1ull>'
#endif


// Matrix::col(size_t)
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix<T,N>::col(size_t n)
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

// Matrix::col(size_t) const
template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,data()};
}

// fortran style index access: enabled when size_t indexes access only
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), T&>
	Matrix<T,N>::operator()(Args... args)
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(data() + desc(args...));
	}

// fortran style index access for const Matrix: returns const T
//	: enabled when size_t indexes access only
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), const T&>
	Matrix<T,N>::operator()(Args... args) const
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(data() + desc(args...));
	}

// slice index access for non-const Matrix<T,N>
//	returns Matrix_ref<T,N>
//	: enabled when having size_t or slice index and having at least one slice index
template<typename T,size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<T,N>>
	Matrix<T,N>::operator()(const Args&... args)
	{
		Matrix_slice<N> d;
		d.size = 1; // 2016.11.13 add: do_slice multiplies d.size by each ns.extents[i]
		d.start = Matrix_impl::do_slice(desc,d,args...);
		return {d,data()};
	}

// slice index access for const Matrix<N,T>
//	returns Matrix_ref<const T,N>
//	: enabled when having size_t or slice index and having at least one slice index
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<const T,N>>
	Matrix<T,N>::operator()(const Args&... args) const
	{
		Matrix_slice<N> d;
		d.size = 1; // 2016.11.13 add
		d.start = Matrix_impl::do_slice(desc,d,args...);
		return {d,data()};	// type of data() is 'const T*'
	}



#endif /* MATRIX_BODY_IMPL_H_ */
