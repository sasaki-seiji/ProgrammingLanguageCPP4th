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


template<typename T, size_t N>
Matrix<T,N> operator+(const Matrix_ref<T,N>& x, const T& n)
{
	Matrix<T,N> res = x;
	res+=n;
	return res;
}




#endif /* MATRIX_REF_IMPL_H_ */
