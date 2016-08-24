/*
 * Expr.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef EXPR_H_
#define EXPR_H_

class Expr {
public:
	Expr();
	Expr(const Expr&);
	virtual Expr* new_expr() = 0;
	virtual Expr* clone() = 0;

	virtual void print() const = 0;
};

#endif /* EXPR_H_ */
