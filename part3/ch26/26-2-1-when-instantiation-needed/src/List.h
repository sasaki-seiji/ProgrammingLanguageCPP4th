/*
 * List.h
 *
 *  Created on: 2017/06/01
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

//#include <vector>
#include <algorithm>
#include <iostream>

template<typename T> class Link;
template<typename T> class List;

template<typename T>
class Link {
	T val;
	Link* suc;

public:
	Link(const T& v={}) : val{v}, suc{nullptr} { }

	friend class List<T>;
};

template<typename T>
class List {
	Link<T> *head;

public:
	void sort();

	List() :head{nullptr} { }
	List(std::initializer_list<T> il);
	void print(std::ostream& os);
};

template<typename T>
List<T>::List(std::initializer_list<T> il)
	:head{nullptr}
{
	Link<T> **last = &head;
	for (auto x : il) {
		*last = new Link<T>{x};
		last = &((*last)->suc);
	}
}

template<typename T>
void List<T>::print(std::ostream& os)
{
	Link<T> *cur = head;
	os << "[ ";
	while (cur) {
		os << cur->val << ' ';
		cur = cur->suc;
	}
	os << "]\n";
}

// selection sort
template<typename T>
void List<T>::sort()
{
	for (Link<T> *i = head; i; i = i->suc) {
		Link<T> *min_pos = i;
		T min_val = i->val;
		for (Link<T> *j = i->suc; j; j = j->suc)
			if (j->val < min_val) {
				min_pos = j;
				min_val = j->val;
			}
		T temp = i->val;
		i->val = min_pos->val;
		min_pos->val = temp;
	}
}

#endif /* LIST_H_ */
