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
class Link {
	template<typename U, typename A>
		friend class List;
	T val;
	Link* succ;
	Link* prev;

	Link(const T&v = T{}) : val{v}, succ{this}, prev{this} { }
	void insert_before(Link* p)
		{ prev->succ = p; p->prev = prev; p->succ = this; prev = p; }
	void insert_after(Link* p)
		{ succ->prev = p; p->succ = succ; p->prev = this; succ = p; }
	Link* unlink()
		{ prev->succ = succ; succ->prev = prev; return this; }
};

template<typename T, typename Allocator>
class List {
private:
	Link<T> head;
	size_t sz;
	Allocator alloc;

public:
	List() : sz{0}, alloc{Allocator{}} { }
	List(const List&) = delete;
	List& operator=(const List&) = delete;
	~List() { clear(); }

	bool empty() { return sz == 0; }
	size_t size() { return sz; }
	void clear();

	void push_front(const T&);
	T& front();
	void pop_front();
	void print_all(std::ostream&);
};


template<typename T, typename A>
void List<T,A>::clear()
{
	while(!empty()) pop_front();
}

template<typename T, typename A>
void List<T,A>::push_front(const T& v)
{
	Link<T> *p = static_cast<Link<T>*>(alloc.allocate(sizeof(Link<T>)));
	new(p) Link<T>(v);

	head.insert_after(p);
	++sz;
}

template<typename T, typename A>
T& List<T,A>::front()
{
	return head.succ->val;
}

template<typename T, typename A>
void List<T,A>::pop_front()
{
	Link<T> *p = head.succ->unlink();
	--sz;
	(p->val).~T();
	alloc.deallocate(p, sizeof(Link<T>));
}

template<typename T, typename A>
void List<T,A>::print_all(std::ostream& os)
{
	Link<T> *cur = head.succ;
	while (cur!=&head) {
		os << cur->val << ' ';
		cur = cur->succ;
	}
	os << '\n';
}
#endif /* LIST_H_ */
