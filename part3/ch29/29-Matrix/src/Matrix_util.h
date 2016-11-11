/*
 * Matrix_util.h
 *
 *  Created on: 2016/11/03
 *      Author: sasaki
 */

#ifndef MATRIX_UTIL_H_
#define MATRIX_UTIL_H_

constexpr bool All() { return true; }

template<typename... Args>
constexpr bool All(bool b, Args... args)
{
	return b && All(args...);
}

constexpr bool Some() { return false; }

template<typename... Args>
constexpr bool Some(bool b, Args... args)
{
	return b || Some(args...);
}


struct slice {
	slice() :start(-1), length(-1), stride(1) { }
	explicit slice(size_t s) :start(s), length(-1), stride(1) { }
	slice(size_t s, size_t l, size_t n = 1) :start(s), length(l), stride(n) { }

	size_t operator()(size_t i) const { return start+i*stride; }

	static slice all;

	size_t start;
	size_t length;
	size_t stride;
};

template<size_t N>
struct Matrix_slice {
	// 2016.11.06 change
	//Matrix_slice() = default;
	Matrix_slice();

	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts);
	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts,	std::initializer_list<size_t> strs);

	template<typename... Dims>
		Matrix_slice(Dims... dims);

	template<typename... Dims,
			typename = Enable_if<All(Convertible<Dims,size_t>()...)>>
		size_t operator()(Dims... dims) const;

	// 2016.11.09 add: for index array access
	size_t at(std::array<size_t,N>& i) const;

	size_t size;
	size_t start;
	std::array<size_t,N> extents;
	std::array<size_t,N> strides;
};

template<size_t N>
Matrix_slice<N>::Matrix_slice()
	: size(0), start(0)
{
	for (auto& elem : extents)
		elem = 0;
	for (auto& elem : strides)
		elem = 0;
}

template<size_t N>
Matrix_slice<N>::Matrix_slice(size_t offset,std::initializer_list<size_t> exts)
{
	assert(exts.size()==N);
	start = offset;
	int i = 0;
	for (auto it=exts.begin(); it!=exts.end(); ++it, ++i)
		extents[i] = *it;
	size = 1;
	for (int i = N-1; i>=0; --i) {
		strides[i] = size;
		size *= extents[i];
	}
}

template<size_t N>
Matrix_slice<N>::Matrix_slice(size_t offset, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs)
{
	assert(exts.size()==N && strs.size()==N);
	start = offset;
	int i = 0;
	for (auto ie=exts.begin(), is=strs.begin(); ie!=exts.end();
			++ie, ++is, ++i) {
		extents[i] = *ie;
		strides[i] = strs;
	}
	size = 1;
	for (int i = N-1; i>=0; --i)
		size *= extents[i];
}

template<size_t N>
	template<typename... Dims>
	Matrix_slice<N>::Matrix_slice(Dims... dims)
	{
		static_assert(sizeof...(Dims)==N,
				"Matrix_slice<N>::operator(): dimension mismatch");
		start = 0;
		size_t args[N] = { size_t(dims)... };
		for (size_t i=0; i<N; ++i)
			extents[i] = args[i];
		size = 1;
		for (int i = N-1; i>=0; --i) {
			strides[i] = size;
			size *= extents[i];
		}
	}

template<size_t N>
	template<typename... Dims,typename>
	size_t Matrix_slice<N>::operator()(Dims... dims) const
	{
		static_assert(sizeof...(Dims)==N,
				"Matrix_slice<N>::operator(): dimension mismatch");
		size_t args[N] { size_t(dims)... };
		return start+std::inner_product(args,args+N,strides.begin(), size_t{0});
	};

template<size_t N>
size_t Matrix_slice<N>::at(std::array<size_t,N>& i) const
{
	return start + std::inner_product(i.begin(), i.end(), strides.begin(), size_t{0});
}


// specialize Matrix_slice to N=1

template<>
struct Matrix_slice<1> {

	Matrix_slice()
		: size(0), start(0)
	{
		extents[0] = strides[0] = 0;
	}


	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts)
	{
		assert(exts.size()==1);
		start = offset;
		extents[0] = *exts.begin();
		size = extents[0];
		strides[0] = 1;
	}
	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts,	std::initializer_list<size_t> strs)
	{
		assert(exts.size()==1 && strs.size()==1);
		start = offset;
		extents[0] = *exts.begin();
		strides[0] = *strs.begin();
		size = extents[0];
	}

	Matrix_slice(size_t s)
	{
		size = s; start = 0; extents[0] = s; strides[0] = 1;
	}

	size_t operator()(size_t i) const
	{
		return start+i*strides[0];
	}

	// 2016.11.09 add: for index array access
	size_t at(std::array<size_t,1>& i) const
	{
		return start + i[0]*strides[0];
	}

	size_t size;
	size_t start;
	std::array<size_t,1> extents;
	std::array<size_t,1> strides;
};

// specialize Matrix_slice to N=2

template<>
struct Matrix_slice<2> {

	Matrix_slice()
		: size(0), start(0)
	{
		extents[0] = extents[1] = 0;
		strides[0] = strides[1] = 0;
	}

	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts)
	{
		assert(exts.size()==2);
		start = offset;
		auto it = exts.begin();
		extents[0] = *it++; extents[1] = *it;
		size = extents[0]*extents[1];
		strides[1] = 1; strides[0] = extents[1];
	}

	Matrix_slice(size_t offset,
			std::initializer_list<size_t> exts,	std::initializer_list<size_t> strs)
	{
		assert(exts.size()==2 && strs.size()==2);
		start = offset;
		auto ie = exts.begin();
		extents[0] = *ie++; extents[1] = *ie;
		auto is = strs.begin();
		strides[0] = *is++; strides[1] = *is;
		size = extents[0]*extents[1];
	}

	Matrix_slice(size_t e1, size_t e2)
	{
		start = 0;
		extents[0] = e1; extents[1] = e2;
		size = e1*e2;
		strides[1] = 1; strides[0] = e2;
	}

	size_t operator()(size_t i, size_t j) const
	{
		return start+i*strides[0]+j*strides[1];
	}

	// 2016.11.09 add: for index array access
	size_t at(std::array<size_t,2>& i) const
	{
		return start + i[0]*strides[0] + i[1]*strides[1];
	}

	size_t size;
	size_t start;
	std::array<size_t,2> extents;
	std::array<size_t,2> strides;
};

// 2016.11.10 add: for debug

template<size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<size_t,N>& arr)
{
	for (size_t sz : arr)
		os << sz << ',';
	return os;
}

template<size_t N>
std::ostream& operator<<(std::ostream& os, const Matrix_slice<N>& ms)
{
	os << "size: " << ms.size << ", start: " << ms.start
			<< ", extents: " << ms.extents
			<< " strides: " << ms.strides;
	return os;
}

// 2016.11.10 add:

template<typename M>
	Enable_if<Matrix_type<M>(),std::ostream&>
operator<<(std::ostream& os, const M& m)
{
	os << '{';
	for (size_t i = 0; i!=m.rows(); ++i) {
		os << m[i];
		if (i+1!=m.rows()) os << ',';
	}
	return os << '}';
}

// 2016.11.11 add:

template<size_t N>
bool same_extents(const Matrix_slice<N>& a, const Matrix_slice<N>& b)
{
	return a.extents == b.extents;
}


#endif /* MATRIX_UTIL_H_ */
