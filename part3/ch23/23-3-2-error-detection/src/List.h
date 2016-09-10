/*
 * List.h
 *
 *  Created on: 2016/09/10
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using std::cout;

template<typename T>
struct Link {
	Link* pre;
	//Link* suc
		// error: expected ';' at end of member declaration
	Link* suc;
	T val;
};

template<typename T>
class List {
	Link<T> *head;
public:
	//List() : head{7} { }
		// error: invalid conversion from 'int' to 'Link<int>*' [-fpermissive]
	List() : head{nullptr} { }
	//List(const T& t) : head{new Link<T>{0,o,t}} { }
		// error: 'o' was not declared in this scope
	List(const T& t) : head{new Link<T>{0,0,t}} { }

	void print_all() const;

	// 2016.09.10 add
	void add_head(const T& t);
};

template<typename T>
void List<T>::print_all() const
{
	for (Link<T>* p = head; p; p=p->suc)
		//cout << *p;
			// error: no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'Link<int>')
		cout << p->val << '\n';
			// error: no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'Rec')
	cout << '\n'; // 2016.09.10 add
}

// 2016.09.10 add
template<typename T>
void List<T>::add_head(const T& t)
{
	Link<T> *p = new Link<T>{0,0,t};
	if (head) {
		head->pre = p;
		p->suc = head;
	}
	head = p;
}

#endif /* LIST_H_ */
