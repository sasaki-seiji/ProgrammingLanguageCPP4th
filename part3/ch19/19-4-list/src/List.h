/*
 * List.h
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

class List;

class List_iterator {
	List* cur;
public:
	List_iterator(List* p) : cur{p} { }
	void reset(List* p) { cur = p; }

	int *next();
};

class List {
	int value;
	List* next;
public:
	List(int v) : value{v}, next{nullptr} { }

	List* add_head(List* link);
	List* add_tail(List* link);

	friend int* List_iterator::next();
};

#endif /* LIST_H_ */
