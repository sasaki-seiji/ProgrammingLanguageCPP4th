/*
 * Xref.h
 *
 *  Created on: 2016/09/15
 *      Author: sasaki
 */

#ifndef XREF_H_
#define XREF_H_

#include <iostream>
using namespace std;

template<typename T>
class Xref {
public:
	Xref(int i, T* p)
		:index{i}, elem{p}, owned{true}
	{ cout << "Xref(int:" << index <<",T*:" << *elem << ")\n"; }

	Xref(int i, T& r)
		:index{i}, elem{&r}, owned{false}
	{ cout << "Xref(int:" << index << ",T&:" << *elem << ")\n"; }

	Xref(int i, T&& r)
		:index{i}, elem{new T{move(r)}}, owned{true}
	{ cout << "Xref(int:" << index << ",T&&:" << *elem << ")\n"; }

	~Xref()
	{
		cout << "~Xref(): index=" << index << ",*elem=" << *elem << ",owned=" << owned << "\n";
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
