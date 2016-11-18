/*
 * Matrix_ref.h
 *
 *  Created on: 2016/11/07
 *      Author: sasaki
 */

#ifndef MATRIX_REF_IMPL_H_
#define MATRIX_REF_IMPL_H_


// 2016.11.09 add: Matrix_ref_iterator method

template<typename T, size_t N>
bool Matrix_ref_iterator<T,N>::operator==(const Matrix_ref_iterator<T,N>& other) const
{
	return this->ref == other.ref && this->cur == other.cur;
}

// increment indexes of Matrix_ref_iterator :
// 	- from lowest(N-1) to highest(0)
template<typename T, size_t N>
Matrix_ref_iterator<T,N>& Matrix_ref_iterator<T,N>::operator++()
{
	int i = N-1;
	while (i >= 0) {
		++cur[i];
		if (cur[i] < ref->extent(i)) return *this;
		cur[i] = 0;
		--i;
	}

	// reach to end
	cur[0] = ref->extent(0);
	return *this;
}

template<typename T, size_t N>
T& Matrix_ref_iterator<T,N>::operator*()
{
	return ref->at(cur);
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N>
Matrix_ref_iterator<T,N>::begin(Matrix_ref<T,N>* ref)
{
	Matrix_ref_iterator iter(ref);
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N>
Matrix_ref_iterator<T,N>::end(Matrix_ref<T,N>* ref)
{
	Matrix_ref_iterator iter(ref);
	iter.cur[0] = ref->extent(0);
	return iter;
}

template<typename T, size_t N>
Matrix_ref_iterator<T,N>::Matrix_ref_iterator(Matrix_ref<T,N>* ref)
	: ref(ref)
{
	for (auto& x : cur) x = 0;
}


// 2016.11.09 add: Matrix_ref_const_iterator method

template<typename T, size_t N>
bool Matrix_ref_const_iterator<T,N>::operator==(const Matrix_ref_const_iterator<T,N>& other) const
{
	return this->ref == other.ref && this->cur == other.cur;
}

template<typename T, size_t N>
Matrix_ref_const_iterator<T,N>& Matrix_ref_const_iterator<T,N>::operator++()
{
	int i = N-1;
	while (i >= 0) {
		++cur[i];
		if (cur[i] < ref->extent(i)) return *this;
		cur[i] = 0;
		--i;
	}

	// reach to end
	cur[0] = ref->extent(0);
	return *this;
}

template<typename T, size_t N>
const T& Matrix_ref_const_iterator<T,N>::operator*()
{
	return ref->at(cur);
}

template<typename T, size_t N>
Matrix_ref_const_iterator<T,N>
Matrix_ref_const_iterator<T,N>::begin(const Matrix_ref<T,N>* ref)
{
	Matrix_ref_const_iterator iter(ref);
	return iter;
}

template<typename T, size_t N>
Matrix_ref_const_iterator<T,N>
Matrix_ref_const_iterator<T,N>::end(const Matrix_ref<T,N>* ref)
{
	Matrix_ref_const_iterator iter(ref);
	iter.cur[0] = ref->extent(0);
	return iter;
}

template<typename T, size_t N>
Matrix_ref_const_iterator<T,N>::Matrix_ref_const_iterator(const Matrix_ref<T,N>* ref)
	: ref(ref)
{
	for (auto& x : cur) x = 0;
}


//2016.11.10 add: assign Matrix_initializer

template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator=(Matrix_initializer<T,N> init)
{
	std::array<size_t, N> extents = Matrix_impl::derive_extents<N>(init);
	assert(extents == desc.extents);

	iterator it = begin();
	Matrix_impl::copy_flat(init, it);

	return *this;
}

// Matrix_ref: fortran style index access
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), T&>
	Matrix_ref<T,N>::operator()(Args... args)
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(ptr + desc(args...));
	}

// Matrix_ref: fortran style index access - const version
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_element<Args...>(), const T&>
	Matrix_ref<T,N>::operator()(Args... args) const
	{
		assert(Matrix_impl::check_bounds(desc, args...));
		return *(ptr + desc(args...));
	}

// Matrix_ref: slice access
template<typename T,size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<T,N>>
	Matrix_ref<T,N>::operator()(const Args&... args)
	{
		Matrix_slice<N> d;
		d.size = 1; // 2016.11.13 add
		d.start = desc.start + Matrix_impl::do_slice(desc,d,args...);
		return {d,ptr};
	}

// Matrix_ref: slice access - const version
template<typename T, size_t N>
	template<typename... Args>
	Enable_if<Matrix_impl::Request_slice<Args...>(), Matrix_ref<const T,N>>
	Matrix_ref<T,N>::operator()(const Args&... args) const
	{
		Matrix_slice<N> d;
		d.size = 1; // 2016.11.13 add
		d.start = desc.start + Matrix_impl::do_slice(desc,d,args...);
		return {d,ptr};
	}


// 2016.11.08 add: row()

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M>1),Matrix_ref<T,M-1>> Matrix_ref<T,N>::row(size_t n)
	{
		assert(n<rows());
		Matrix_slice<N-1> row;
		Matrix_impl::slice_dim<0>(n,desc,row);
		return {row,ptr};
	}

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M==1),T&> Matrix_ref<T,N>::row(size_t i)
	{
		return *(ptr + desc(i));
	}

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M>1),Matrix_ref<const T,M-1>>
	Matrix_ref<T,N>::row(size_t n) const
{
	assert(n<rows());
	Matrix_slice<N-1> row;
	Matrix_impl::slice_dim<0>(n,desc,row);
	return {row,ptr};
}

template<typename T, size_t N>
	template<size_t M>
	Enable_if<(M==1),const T&>
	Matrix_ref<T,N>::row(size_t i) const
{
	return *(ptr + desc(i));
}

// Matrix_ref::col(size_t)
template<typename T, size_t N>
Matrix_ref<T,N-1> Matrix_ref<T,N>::col(size_t n)
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,ptr};
}

// Matrix_ref::col(size_t) const
template<typename T, size_t N>
Matrix_ref<const T,N-1> Matrix_ref<T,N>::col(size_t n) const
{
	assert(n<cols());
	Matrix_slice<N-1> col;
	Matrix_impl::slice_dim<1>(n,desc,col);
	return {col,ptr};
}

// Matrix_ref::apply(f) - apply function to all element of Matrix_ref
template<typename T, size_t N>
	template<typename F>
	Matrix_ref<T,N>& Matrix_ref<T,N>::apply(F f)
	{
		for (auto& x : *this) f(x);
		return *this;
	}

// Matrix_ref = scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator=(const T& val)
{
	return apply([&](T& a){ a=val; });
}

// Matrix_ref += scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator+=(const T& val)
{
	return apply([&](T& a){ a+=val; });
}

// Matrix_ref -= scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator-=(const T& val)
{
	return apply([&](T& a){ a-=val; });
}

// Matrix_ref *= scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator*=(const T& val)
{
	return apply([&](T& a){ a*=val; });
}

// Matrix_ref /= scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator/=(const T& val)
{
	return apply([&](T& a){ a/=val; });
}

// Matrix_ref %= scalar
template<typename T, size_t N>
Matrix_ref<T,N>& Matrix_ref<T,N>::operator%=(const T& val)
{
	return apply([&](T& a){ a%=val; });
}

// Matrix_ref + scalar
template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix_ref<T,N>& x, const T& val)
{
	Matrix<T,N> res = x;
	res+=val;
	return res;
}

// Matrix_ref - scalar
template<typename T, size_t N>
Matrix<T,N> operator-(const Matrix_ref<T,N>& x, const T& val)
{
	Matrix<T,N> res = x;
	res-=val;
	return res;
}

// Matrix_ref * scalar
template<typename T, size_t N>
Matrix<T,N> operator*(const Matrix_ref<T,N>& x, const T& val)
{
	Matrix<T,N> res = x;
	res*=val;
	return res;
}

// Matrix_ref / scalar
template<typename T, size_t N>
Matrix<T,N> operator/(const Matrix_ref<T,N>& x, const T& val)
{
	Matrix<T,N> res = x;
	res/=val;
	return res;
}

// Matrix_ref % scalar
template<typename T, size_t N>
Matrix<T,N> operator%(const Matrix_ref<T,N>& x, const T& val)
{
	Matrix<T,N> res = x;
	res%=val;
	return res;
}

// Matrix_ref::apply:
//	apply f between *this elements and Matrix_type elements
template<typename T, size_t N>
	template<typename M, typename F>
	Enable_if<Matrix_type<M>(),Matrix_ref<T,N>&> Matrix_ref<T,N>::apply(const M& m, F f)
	{
		assert(same_extents(desc,m.descriptor()));
		for (auto i = begin(), j = m.begin(); i!=end(); ++i, ++j)
			f(*i,*j);
		return *this;
	}


// Matrix_ref += Matrix_type
template<typename T, size_t N>
	template<typename M>
	Enable_if<Matrix_type<M>(),Matrix_ref<T,N>&> Matrix_ref<T,N>::operator+=(const M& m)
	{
		static_assert(m.order==N,"+=: mismatched Matrix_ref dimensions");
		assert(same_extents(desc,m.descriptor()));

		return apply(m, [](T& a, const Value_type<M>& b){ a+=b; });
	}

// Matrix_ref + Matrix
template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix_ref<T,N>& a, const Matrix<T,N>& b)
{
	Matrix<T,N> res = a;
	res+=b;
	return res;
}


#endif /* MATRIX_REF_IMPL_H_ */
