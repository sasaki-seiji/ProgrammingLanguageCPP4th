/*
 * user.cpp
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */


#include "Expr.h"
#include "Cond.h"
#include "Addition.h"
#include <iostream>
using namespace std;

void user(Expr* p)
{
	cout << "-- user(Expr*) --\n";

	Expr* p2 = p->new_expr();
	p2->print();
}

void user2(Cond* pc, Addition* pa)
{
	cout << "-- user2(Cond*,Additon*) --\n";

	Cond* p1 = pc->clone();
	Addition* p2 = pa->clone();

	p1->print();
	p2->print();
}

void user3(Cond* pc, Expr* pe)
{
	cout << "-- user3(Cond*,Expr*) --\n";

	Cond* p1 = pc->clone();
	//Cond* p2 = pe->clone();
		//error: invalid conversion from 'Expr*' to 'Cond*' [-fpermissive]
	Expr* p2 = pe->clone();

	p1->print();
	p2->print();
}

// add main

int main()
{
	Cond c;
	user(&c);

	Addition a;
	user2(&c, &a);

	user3(&c, &a);
}

