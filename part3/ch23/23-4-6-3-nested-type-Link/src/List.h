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
class List {
private:
	struct Link {
		T val;
		Link* succ;
		Link* prev;
	};

	Link* head;
	Allocator alloc;
public:
	List() : head{nullptr}, alloc{Allocator{}} { }
	void add_head(const T&);
	void print_all(std::ostream&);
};


template<typename T, typename A>
void List<T,A>::add_head(const T& v)
{
	Link *p = static_cast<Link*>(alloc.allocate(sizeof(Link)));
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
	Link *cur = head;
	while (cur) {
		os << cur->val << ' ';
		cur = cur->succ;
	}
	os << '\n';
}
#endif /* LIST_H_ */
