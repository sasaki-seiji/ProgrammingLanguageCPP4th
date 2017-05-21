/*
 * List.h
 *
 *  Created on: 2017/05/21
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

#include <initializer_list>

template<typename T>
struct Link {
	T val;
	Link *next;
};

template<typename T>
struct List_iterator {
	Link<T> *pos;

	T& operator*() { return pos->val; }
	List_iterator& operator++() { pos = pos->next; return *this; }
	bool operator==(const List_iterator& o) { return pos == o.pos; }
};

template<typename T>
class List {
	Link<T> *head;
public:
	using iterator = List_iterator<T>;

	List() : head{nullptr} {}
	List(std::initializer_list<T>);
	List(const List&) = delete;
	List& operator=(const List&) = delete;
	~List() { clear(); }

	bool empty() const { return head == nullptr; }
	void clear();
	void pop_front();

	iterator begin() { return List_iterator<T>{head}; }
	iterator end() { return List_iterator<T>{nullptr}; }
};

template<typename T>
List<T>::List(std::initializer_list<T> il)
	: head{nullptr}
{
	Link<T> **last = &head;
	for (auto x : il) {
		Link<T> *add = new Link<T>{x, nullptr};
		*last = add;
		last = &(add->next);
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (head) {
		Link<T> *p = head;
		head = p->next;
		delete p;
	}
}

template<typename T>
void List<T>::clear()
{
	while (!empty()) {
		pop_front();
	}
}

#endif /* LIST_H_ */
