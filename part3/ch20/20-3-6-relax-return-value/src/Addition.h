/*
 * Addition.h
 *
 *  Created on: 2016/08/24
 *      Author: sasaki
 */

#ifndef ADDITION_H_
#define ADDITION_H_

#include "Expr.h"

class Addition : public Expr{
public:
	Addition();
	Addition(const Addition&);
	Addition* new_expr() override { return new Addition(); }
	Addition* clone() override { return new Addition(*this); }

	void print() const override;
};

#endif /* ADDITION_H_ */
