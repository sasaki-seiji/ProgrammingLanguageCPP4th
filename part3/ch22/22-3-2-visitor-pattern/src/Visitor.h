/*
 * Visitor.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef VISITOR_H_
#define VISITOR_H_

#include <iostream>
using std::cout;

class Expr;
class Stmt;

class Visitor {
public:
	virtual void accept(Expr&) = 0;
	virtual void accept(Stmt&) = 0;

	virtual ~Visitor() { }
};

struct Do1_visitor : public Visitor {
	void accept(Expr&) override { cout << "do1 to Expr\n"; }
	void accept(Stmt&) override { cout << "do1 to Stmt\n"; }
};

struct Do2_visitor : public Visitor {
	void accept(Expr&) override { cout << "do2 to Expr\n"; }
	void accept(Stmt&) override { cout << "do2 to Stmt\n"; }
};


// 2016.09.04 add

class Node_counter : public Visitor {
public:
	void accept(Expr&) override;
	void accept(Stmt&) override;

	Node_counter();
	void clear();
	int expr_count() const { return cexpr; }
	int stmt_count() const { return cstmt; }
private:
	int cexpr;
	int cstmt;
};

#endif /* VISITOR_H_ */
