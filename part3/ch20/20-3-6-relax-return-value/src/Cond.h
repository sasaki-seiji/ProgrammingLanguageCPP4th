/*
 * Cond.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef COND_H_
#define COND_H_

#include "Expr.h"

class Cond : public Expr{
public:
	Cond();
	Cond(const Cond&);
	Cond* new_expr() override { return new Cond(); }
	Cond* clone() override { return new Cond(*this); }

	void print() const override;
};

#endif /* COND_H_ */
