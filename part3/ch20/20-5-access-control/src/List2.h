/*
 * List2.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef LIST2_H_
#define LIST2_H_

class Underflow2 { };

template<typename T>
struct Link2 {
	T val;
	Link2* next;
};

template<typename T>
struct Chunk2 {
	enum { chunk_size = 15 };
	Link2<T> v[chunk_size];
	Chunk2* next;
};

template<typename T>
class List2 {
public:
	List2() : allocated{nullptr}, free{nullptr}, head{nullptr} { }
	~List2();

	void insert(T);
	T get();
private:
	Chunk2<T>* allocated;
	Link2<T>* free;
	Link2<T>* get_free();
	Link2<T>* head;
};

template<typename T>
List2<T>::~List2()
{
	while (Chunk2<T>* top = allocated) {
		allocated = top->next;
		delete top;
	}
}

template<typename T>
void List2<T>::insert(T val)
{
	Link2<T>* lnk = get_free();
	lnk->val = val;
	lnk->next = head;
	head = lnk;
}

template<typename T>
T List2<T>::get()
{
	if (head == nullptr)
		throw Underflow2{ };

	Link2<T>* p = head;
	head = p->next;
	p->next = free;
	free = p;
	return p->val;
}

template<typename T>
Link2<T>* List2<T>::get_free()
{
	if (free == nullptr) {
		Chunk2<T>* chunk = new Chunk2<T>;
		chunk->next = allocated;
		allocated = chunk;

		for ( int i = 0; i < Chunk2<T>::chunk_size-1; ++i)
			chunk->v[i].next = &chunk->v[i+1];
		chunk->v[Chunk2<T>::chunk_size-1].next = free;
		free = &chunk->v[0];
	}

	Link2<T>* p = free;
	free = p->next;
	return p;
}

#endif /* LIST2_H_ */
