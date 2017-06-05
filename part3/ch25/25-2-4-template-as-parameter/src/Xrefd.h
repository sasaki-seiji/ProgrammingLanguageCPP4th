/*
 * Xrefd.h
 *
 *  Created on: 2017/06/04
 *      Author: sasaki
 */

#ifndef XREFD_H_
#define XREFD_H_

#include <algorithm>

template<typename T, template<typename> class C>
class Xrefd {
	C<T> mems;
	C<T*> refs;

public:
	using iterator = typename C<T*>::iterator;

	void add(const T& v) { mems.push_back(v); }
	void make_ref() ;
	template<typename Compare>
		void sort_ref(const Compare& cmp);

	iterator begin() { return refs.begin(); }
	iterator end() { return refs.end(); }
};

template<typename T, template<typename> class C>
void Xrefd<T,C>::make_ref()
{
	refs.clear();
	for (auto& x : mems)
		refs.push_back(&x);
}

template<typename T, template<typename> class C>
template<typename Compare>
void Xrefd<T,C>::sort_ref(const Compare& cmp)
{
	std::sort(refs.begin(), refs.end(), cmp);
}



#endif /* XREFD_H_ */
