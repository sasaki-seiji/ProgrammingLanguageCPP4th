/*
 * Xrefd2.h
 *
 *  Created on: 2017/06/05
 *      Author: sasaki
 */

#ifndef XREFD2_H_
#define XREFD2_H_


template<typename C, typename C2>
class Xrefd2 {
	C mems;
	C2 refs;

public:
	using iterator = typename C2::iterator;
	using value_type = typename C::value_type;

	void add(const value_type& v) { mems.push_back(v); }
	void make_ref() ;

	iterator begin() { return refs.begin(); }
	iterator end() { return refs.end(); }

};

template<typename C, typename C2>
void Xrefd2<C,C2>::make_ref()
{
	refs.clear();
	for (auto& e : mems)
		refs.insert(&e);
}


#endif /* XREFD2_H_ */
