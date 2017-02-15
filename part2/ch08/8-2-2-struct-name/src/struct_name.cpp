/*
 * struct_name.cpp
 *
 *  Created on: 2016/04/17
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

struct Link {
	Link* previous;
	Link* successor;
};

struct No_good {
	//No_good member;
		// error: field 'member' has incomplete type 'No_good'
};

struct List2;

struct Link2 {
	Link2* pre;
	Link2* suc;
	List2* member_of;
	int data;
};


struct List2 {
	Link2* head;
};

void print_list2(List2 *list2)
{
	for (Link2 *lk2 = list2->head; lk2; lk2 = lk2->suc) {
		cout << lk2->data << ' ';
	}
	cout << endl;
}

struct S;

extern S a;
S f();
void g(S);
S* h(S*);

void k(S* p)
{
	cout << "-- k(S* " << p << ") --\n";

	//S a;
		// error: aggregate 'S a' has incomplete type and cannot be defined
	//f();
		// error: invalid use of incomplete type 'struct S'
	//g(a);
		// error: invalid use of incomplete type 'struct S'
	//p->m = 7;
		// error: invalid use of incomplete type 'struct S'
	S* q = h(p);
	//q->m = 7;
		// error: invalid use of incomplete type 'struct S'
}

S* h(S* p) { return p; }
struct S { };

struct stat { };
int stat(char* name, struct stat* buf) { return 3; }

int main()
{
	Link *link1 = new Link{nullptr,nullptr};
	link1->successor = new Link{link1,nullptr};

	List2 list2;
	Link2 *link2_1 = new Link2{nullptr, nullptr, &list2, 100};
	list2.head = link2_1;
	link2_1->suc = new Link2{link2_1, nullptr, &list2, 1000};
	print_list2(&list2);

	S s;
	k(&s);

	cout << "stat() = " << stat("", nullptr) << endl;
}
