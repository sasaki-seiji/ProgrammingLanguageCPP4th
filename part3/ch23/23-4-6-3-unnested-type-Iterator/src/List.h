/*
 * List.h
 *
 *  Created on: 2016/09/11
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

#include <memory>
#include <ostream>

template<typename T, typename Allocator>
class List;

template<typename T>
struct Iterator;

template<typename T>
class Link {
	template<typename U, typename A>
		friend class List;
	friend struct Iterator<T>;

	T val;
	Link* succ;
	Link* prev;
};

template<typename T>
struct Iterator {
	Link<T>* current_position;

	T& operator*() { return current_position->val; }
	Iterator& operator++()
		{ current_position = current_position->succ; return *this; }
	bool operator!=(Iterator o)
		{ return current_position != o.current_position; }
};

template<typename T, typename Allocator>
class List {
public:
	Iterator<T> begin() { return Iterator<T>{head}; }
	Iterator<T> end() { return Iterator<T>{nullptr}; }

private:
	Link<T>* head;
	Allocator alloc;

public:
	List() : head{nullptr}, alloc{Allocator{}} { }
	void add_head(const T&);
	void print_all(std::ostream&);
};


template<typename T, typename A>
void List<T,A>::add_head(const T& v)
{
	Link<T> *p = static_cast<Link<T>*>(alloc.allocate(sizeof(Link<T>)));
	p->val = v;
	p->prev = p->succ = nullptr;

	if (head) {
		head->prev = p;
		p->succ = head;
	}

	head = p;
}

template<typename T, typename A>
void List<T,A>::print_all(std::ostream& os)
{
	Link<T> *cur = head;
	while (cur) {
		os << cur->val << ' ';
		cur = cur->succ;
	}
	os << '\n';
}

template<typename T>
Iterator<T> find(Iterator<T> b, Iterator<T> e, T v)
{
	Iterator<T> it = b;
	for ( ;it != e; ++it) {
		if (*it == v) return it;
	}
	return e;
}

#endif /* LIST_H_ */
