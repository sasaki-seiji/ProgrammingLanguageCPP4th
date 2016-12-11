/*
 * list.h
 *
 *  Created on: 2016/12/10
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_


#include <memory>
#include <ostream>

template<typename T, typename A = std::allocator<T>>
class List {
private:
	struct Link {
		T val;
		Link *next;
	};
	Link *head;
	using Link_alloc = typename A::template rebind<Link>::other;
	Link_alloc a;

public:
	List() : head{nullptr} { }
	List(A alloc) : head{nullptr}, a{alloc} { }

	void push_front(const T& t);
	void pop_front();

	T& front() { return head->val; }
	T front() const { return head->val; }

	void print(std::ostream&);
};

template<typename T, typename A>
void List<T,A>::push_front(const T& t)
{
	Link* lnk = a.allocate(1);
	a.construct(&lnk->val, t);	// initialize!! not assignment
	lnk->next = head;
	head = lnk;
}

template<typename T, typename A>
void List<T,A>::pop_front()
{
	if (head) {
		Link* tmp = head;
		head = head->next;
		a.deallocate(tmp, 1);
	}
}

template<typename T, typename A>
void List<T,A>::print(std::ostream& os)
{
	Link *cur = head;
	while (cur) {
		os << cur->val;
		if (cur->next) os << ", ";
		cur = cur->next;
	}
	os << std::endl;
}

#endif /* LIST_H_ */
