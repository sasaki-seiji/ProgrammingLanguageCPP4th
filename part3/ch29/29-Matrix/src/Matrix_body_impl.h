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
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");

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
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");

		// 2016.11.12 change
		//desc = x.desc;
		desc.start = 0;
		desc.extents = x.descriptor().extents;
		Matrix_impl::compute_strides(desc);

		elems.assign(x.begin(),x.end());
		return *this;
	}

// 2016.11.11 add
// Matrix construct from other type Matrix
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>::Matrix(const Matrix<U,N>& x)
		:desc{x.descriptor()}, elems(x.begin(),x.end())
	{
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");
	}

// 2016.11.13 add
// Matrix: assign other type Matrix
template<typename T, size_t N>
	template<typename U>
	Matrix<T,N>& Matrix<T,N>::operator=(const Matrix<U,N>& x)
	{
		static_assert(Convertible<U,T>(), "Matrix constructor: incompatible element types");

		std::vector<T> nv{x.begin(),x.end()};
		desc = x.descriptor();
		elems = nv;
	}


template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator+=(const T& val)
{
	return apply([&](T& a){ a+=val; });
}

// 2016.11.11 add
template<typename T, size_t N>
Matrix<T,N>& Matrix<T,N>::operator*=(const T& val)
{
	return apply([&](T& a){ a*=val; });
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

// 2016.11.11 change :
template<typename T, typename T2, size_t N,
	//typename RT = Matrix<Common_type<Value_type<T>,Value_type<T2>>,N>>
	typename RT = Common_type<T,T2>>
Matrix<RT,N> operator+(const Matrix<T,N>& a, const Matrix<T2,N>& b)
{
	Matrix<RT,N> res = a;
	res+=b;
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
T dot_product(const Matrix_ref<T,1>& a, const Matrix_ref<T,1>& b)
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
		return elems[desc.start+i*desc.strides[0]];
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
	return elems[desc.start+i*desc.strides[0]];
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



#endif /* MATRIX_BODY_IMPL_H_ */
