/*
 * Matrix_impl.h
 *
 *  Created on: 2016/11/03
 *      Author: sasaki
 */

#ifndef MATRIX_IMPL_H_
#define MATRIX_IMPL_H_

namespace Matrix_impl {

// Matrix_init (Matrix_initializer)

template<typename T, size_t N>
struct Matrix_init {
	using type = std::initializer_list<typename Matrix_init<T,N-1>::type>;
};

template<typename T>
struct Matrix_init<T,1> {
	using type = std::initializer_list<T>;
};

template<typename T>
struct Matrix_init<T,0> ;


// derive_extents:
//	get matrix extents array from Matrix_initializer

template<size_t N, typename List>
std::array<size_t,N> derive_extents(const List& list)
{
	std::array<size_t,N> a;
	auto f = a.begin();
	add_extents<N>(f,list);
	return a;
}

template<size_t N, typename I, typename List>
Enable_if<(N>1),void> add_extents(I& first, const List& list)
{
	assert(check_non_jagged<N>(list));
	*first++ = list.size();
	add_extents<N-1>(first, *list.begin());
}

template<size_t N, typename I, typename List>
Enable_if<(N==1),void> add_extents(I& first, const List& list)
{
	*first = list.size();
}

template<size_t N, typename List>
bool check_non_jagged(const List& list)
{
	auto i = list.begin();
	for (auto j = i+1; j!=list.end(); ++j)
		if (derive_extents<N-1>(*i) != derive_extents<N-1>(*j))
			return false;
	return true;
}


// compute_strides:
//	calculate size and strides from extents

template<size_t N>
void compute_strides(Matrix_slice<N>& ms)
{
	size_t st = 1;
	for (int i=N-1; i>=0; --i) {
		ms.strides[i] = st;
		st *= ms.extents[i];
	}
	ms.size = st;
}


// insert_flat:
//	append Matrix elements from Matrix_initializer

template<typename T, typename Vec>
void insert_flat(std::initializer_list<T> list, Vec& vec)
{
	add_list(list.begin(),list.end(),vec);
}

template<typename T, typename Vec>
void add_list(const std::initializer_list<T>* first,
		const std::initializer_list<T>* last, Vec& vec)
{
	for (; first!=last; ++first)
		add_list(first->begin(), first->end(), vec);
}

template<typename T, typename Vec>
void add_list(const T* first, const T* last, Vec& vec)
{
	vec.insert(vec.end(),first,last);
}


template<size_t I, size_t N>
void slice_dim(size_t n, const Matrix_slice<N>& os, Matrix_slice<N-1>& ns)
{
	int i = N-1, j = N-2;
	while (i>=0) {
		if (i==I) {
			ns.start = os.start + n*os.strides[i];
			ns.size = os.size / os.extents[i];
			--i;
		}
		else {
			ns.extents[j] = os.extents[i];
			ns.strides[j] = os.strides[i];
			--i;
			--j;
		}
	}
}

template<size_t N, typename... Dims>
bool check_bounds(const Matrix_slice<N>& slice, Dims... dims)
{
	// 2016.11.05 add
	static_assert(sizeof...(Dims)==N, "check_bounds(): dimension mismatch");

	size_t indexes[N] {size_t(dims)...};
#if 0	// 2016.11.06 change
	return std::equal(indexes. indexes+N, slice.extents.begin(), std::less<size_t>{});
		// error: request for member 'indexes' in 'indexes', which is of non-class type 'std::size_t [2] {aka long long unsigned int [2]}'
#else
	for (size_t i = 0; i < N; ++i)
		if (indexes[i] >= slice.extents[i]){
			std::cerr << "Matrix_impl::check_bounds : out of range - indexes[" << i << "]=" << indexes[i] << std::endl << std::flush;
			return false;
		}
	return true;
#endif
}

template<typename... Args>
constexpr bool Request_element()
{
	return All(Convertible<Args,size_t>()...);
}

template<typename... Args>
constexpr bool Request_slice()
{
	return All((Convertible<Args,size_t>() || Same<Args,slice>())...)
			&& Some(Same<Args,slice>()...);
}

template<size_t I, size_t N>
size_t do_slice_dim(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
		size_t n)
{
	int i = N-I;
	ns.strides[i] = os.strides[i];
	ns.extents[i] = 1;
	return n*os.strides[i];
}

template<size_t I, size_t N>
size_t do_slice_dim(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
		const slice& s)
{
	int i = N-I;
	int start, length;

	ns.strides[i] = os.strides[i];

	start = s.start;
	if (start == -1) start = 0;

	length = s.length;
	if (length == -1) length = os.extents[i] - start;

	ns.extents[i] = length;
	ns.size *= ns.extents[i];

	return start*os.strides[i];
}

template<size_t N, typename T, typename... Args>
size_t do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns,
		const T& s, const Args&... args)
{
	size_t m = do_slice_dim<sizeof...(Args)+1>(os,ns,s);
	size_t n = do_slice(os,ns,args...);
	return m+n;
}

template<size_t N>
size_t do_slice(const Matrix_slice<N>& os, Matrix_slice<N>& ns)
{
	return 0;
}

// 2016.11.10 add

template<typename T, typename Iter>
void copy_flat(std::initializer_list<T> init, Iter& it)
{
	for (auto& elem : init)
		copy_flat(elem, it);
}

template<typename T, typename Iter>
void copy_flat(const T& v, Iter& it)
{
	*it = v;
	++it;
}

}

#endif /* MATRIX_IMPL_H_ */
