/*
 * Slice_iter.h
 *
 *  Created on: 2017/01/13
 *      Author: sasaki
 */

#ifndef SLICE_ITER_H_
#define SLICE_ITER_H_

#include <valarray>

template<typename T>
class Slice_iter {
	std::valarray<T> *v;
	std::slice s;
	size_t curr;

	T& ref(size_t i) const { return (*v)[s.start()+i*s.stride()]; }
public:
	Slice_iter(std::valarray<T>*vv, std::slice ss, size_t pos =0)
		: v{vv}, s{ss}, curr{pos} { }

	Slice_iter end() const { return {v,s,s.size()}; }

	Slice_iter& operator++() { ++curr; return *this; }
	Slice_iter operator++(int) { Slice_iter t = *this; ++curr; return t; }

	T& operator[](size_t i) { return ref(i); }
	T& operator()(size_t i) { return ref(i); }
	T& operator*() { return ref(curr); }

	bool operator==(const Slice_iter& q) const
	{
		return curr == q.curr && s.stride() == q.s.stride() && s.start() == q.s.start();
	}
	bool operator!=(const Slice_iter& q) const
	{
		return !(*this==q);
	}
	bool operator<(const Slice_iter& q) const
	{
		return curr < q.curr && s.stride() == q.s.stride() && s.start() == q.s.start();
	}
};


#endif /* SLICE_ITER_H_ */
