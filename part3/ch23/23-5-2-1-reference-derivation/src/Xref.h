/*
 * Xref.h
 *
 *  Created on: 2016/09/15
 *      Author: sasaki
 */

#ifndef XREF_H_
#define XREF_H_

#include <ostream>
using std::ostream;

template<typename T>
class Xref {
public:
	Xref(int i, T* p)
		:index{i}, elem{p}, owned{true}
	{}

	Xref(int i, T& r)
		:index{i}, elem{&r}, owned{false}
	{}

	Xref(int i, T&& r)
		:index{i}, elem{new T{move(r)}}, owned{true}
	{}

	~Xref()
	{
		if (owned) delete elem;
	}

	void print(ostream& os)
	{
		os << "(" << index << ", " << *elem << ") owned: " << owned << '\n';
	}
private:
	int index;
	T*	elem;
	bool	owned;
};



#endif /* XREF_H_ */
