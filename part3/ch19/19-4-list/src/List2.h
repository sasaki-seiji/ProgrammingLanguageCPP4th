/*
 * List2.h
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#ifndef LIST2_H_
#define LIST2_H_


class List2;

class List2_iterator {
	List2* cur;
public:
	List2_iterator(List2* p) : cur{p} { }
	void reset(List2* p) { cur = p; }

	int *next();
};

class List2 {
	int value;
	List2* next;
public:
	List2(int v) : value{v}, next{nullptr} { }
	List2(int v, List2 *suc) : value{v}, next{suc} { }
	~List2() { delete next; }

	friend class List2_iterator;
};
#endif /* LIST2_H_ */
