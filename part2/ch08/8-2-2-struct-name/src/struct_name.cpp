/*
 * struct_name.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

struct Link {
	Link* previous;
	Link* successor;
};

struct No_good {
	//No_good member;
		// field 'member' has incomplete type 'No_good'
};

struct List;

struct Link2 {
	Link2* pre;
	Link2* suc;
	List* member_of;
	int data;
};

struct List {
	Link* head;
};

struct S;

extern S a;
S f();
void g(S);
S* h(S*);

void k(S* p)
{
	//S a;
		// aggregate 'S a' has incomplete type and cannot be defined
	//f();
		// invalid use of incomplete type 'struct S'
	//g(a);
		// invalid use of incomplete type 'struct S'
	//p->m = 7;
		// invalid use of incomplete type 'struct S'
	S* q = h(p);
	//q->m = 7;
		// invalid use of incomplete type 'struct S'
}

S* h(S* p) { return p; }

struct stat { };
int stat(char* name, struct stat* buf);
