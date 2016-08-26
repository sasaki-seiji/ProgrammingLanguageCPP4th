/*
 * List.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef LIST_H_
#define LIST_H_

#include <ostream>

class Underflow { };

template<typename T>
class List {
public:
	List() : allocated{nullptr}, free{nullptr}, head{nullptr} { }
	~List();

	void insert(T);
	T get();
private:
	struct Link { T val; Link* next; };
	struct Chunk {
		enum { chunk_size = 15 };
		Link v[chunk_size];
		Chunk* next;
	};
	Chunk* allocated;
	Link* free;
	Link* get_free();
	Link* head;
};

template<typename T>
List<T>::~List()
{
	while (Chunk* top = allocated) {
		allocated = top->next;
		delete top;
	}
}

template<typename T>
void List<T>::insert(T val)
{
	Link* lnk = get_free();
	lnk->val = val;
	lnk->next = head;
	head = lnk;
}

template<typename T>
T List<T>::get()
{
	if (head == nullptr)
		throw Underflow{ };

	Link* p = head;
	head = p->next;
	p->next = free;
	free = p;
	return p->val;
}

template<typename T>
typename List<T>::Link* List<T>::get_free()
{
	if (free == nullptr) {
		Chunk* chunk = new Chunk;
		chunk->next = allocated;
		allocated = chunk;

		for ( int i = 0; i < Chunk::chunk_size-1; ++i)
			chunk->v[i].next = &chunk->v[i+1];
		chunk->v[Chunk::chunk_size-1].next = free;
		free = &chunk->v[0];
	}

	Link* p = free;
	free = p->next;
	return p;
}

#endif /* LIST_H_ */
