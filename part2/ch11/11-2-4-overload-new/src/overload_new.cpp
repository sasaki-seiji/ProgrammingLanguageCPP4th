/*
 * overload_new.cpp
 *
 *  Created on: 2016/04/30
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class X {
public:
	//X(int i) :x{i} { } // crash !!!
	X(int i) { cout << "X::X(" << i << ") called\n"; }
	~X( ) { cout << "X::~X( ) called\n"; }
private:
	int x;
};

void f(int i)
{
	void* buf = reinterpret_cast<void*>(0xF00F);
	X* p2 = new(buf) X(i);
	cout << "p2: " << p2 << '\n';
}

class Arena {
public:
	virtual void* alloc(size_t) = 0;
	virtual void free(void*) = 0;
};

void* operator new(size_t sz, Arena* a)
{
	return a->alloc(sz);
}

class Persistent_arena : public Arena {
public:
	void* alloc(size_t sz)
	{ cout << "Persistent_arena(" << sz << ")\n"; return buf; }
	void free(void* p)
	{ cout << "Persistent_arena::free(" << p << ")\n"; }
private:
	char	buf[100];
};

class Shared_arena : public Arena {
public:
	void* alloc(size_t sz)
	{ cout << "Shared_arena(" << sz << ")\n"; return buf; }
	void free(void* p)
	{ cout << "Shared_arena(" << p << ")\n"; }
private:
	static char	buf[100];
};
char Shared_arena::buf[100];

Persistent_arena persistent;
Shared_arena shared;
Arena* Persistent = &persistent;
Arena* Shared = &shared;

void destroy(X* p, Arena*a)
{
	p->~X();
	a->free(p);
}

void g(int i)
{
	X* p = new(Persistent) X(i);
	X* q = new(Shared) X(i);

	cout << "p: " << p << '\n';
	cout << "q: " << q << '\n';

	destroy(p, Persistent);
	destroy(q, Shared);
}

int main()
{
	try {
		f(11);
	}
	catch (std::exception& e) {
		cerr << e.what() << '\n';
	}

	g(111);
}

