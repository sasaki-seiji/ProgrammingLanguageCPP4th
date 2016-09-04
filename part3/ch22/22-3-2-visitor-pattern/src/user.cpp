/*
 * user.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */


#include "Node.h"
#include "Visitor.h"
#include <vector>
using namespace std;

Do1_visitor do1;
Do2_visitor do2;

void test(Expr& e, Stmt& s)
{
	vector<pair<Node*,Visitor*>> vs { {&e,&do1}, {&s,&do1}, {&e,&do2}, {&s,&do2} };
	for (auto p : vs)
		p.first->accept(*p.second);
}

void node_count(const vector<Node*>& v)
{
	Node_counter nc;
	for (auto p : v)
		p->accept(nc);

	cout << "Expr count: " << nc.expr_count() << '\n';
	cout << "Stmt count: " << nc.stmt_count() << '\n';
}

// add main

int main()
{
	Expr e;
	Stmt s;
	test(e, s);

	vector<Node*> vec {
		new Expr, new Expr, new Stmt, new Expr, new Stmt, new Stmt, new Expr
	};
	node_count(vec);
}

