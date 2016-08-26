/*
 * List3.h
 *
 *  Created on: 2016/08/26
 *      Author: sasaki
 */

#ifndef LIST3_H_
#define LIST3_H_

class Underflow3 { };

template<typename T> class List3;

template<typename T>
class Link3 {
	friend class List3<T>;
	T val;
	Link3* next;
};

template<typename T>
class Chunk3 {
	friend class List3<T>;
	enum { chunk_size = 15 };
	Link3<T> v[chunk_size];
	Chunk3* next;
};

template<typename T>
class List3 {
public:
	List3() : allocated{nullptr}, free{nullptr}, head{nullptr} { }
	~List3();

	void insert(T);
	T get();
private:
	Chunk3<T>* allocated;
	Link3<T>* free;
	Link3<T>* get_free();
	Link3<T>* head;
};

template<typename T>
List3<T>::~List3()
{
	while (Chunk3<T>* top = allocated) {
		allocated = top->next;
		delete top;
	}
}

template<typename T>
void List3<T>::insert(T val)
{
	Link3<T>* lnk = get_free();
	lnk->val = val;
	lnk->next = head;
	head = lnk;
}

template<typename T>
T List3<T>::get()
{
	if (head == nullptr)
		throw Underflow3{ };

	Link3<T>* p = head;
	head = p->next;
	p->next = free;
	free = p;
	return p->val;
}

template<typename T>
Link3<T>* List3<T>::get_free()
{
	if (free == nullptr) {
		Chunk3<T>* chunk = new Chunk3<T>;
		chunk->next = allocated;
		allocated = chunk;

		for ( int i = 0; i < Chunk3<T>::chunk_size-1; ++i)
			chunk->v[i].next = &chunk->v[i+1];
		chunk->v[Chunk3<T>::chunk_size-1].next = free;
		free = &chunk->v[0];
	}

	Link3<T>* p = free;
	free = p->next;
	return p;
}


#endif /* LIST3_H_ */
