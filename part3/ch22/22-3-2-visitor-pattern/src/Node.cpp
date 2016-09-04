/*
 * Node.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Node.h"
#include "Visitor.h"

void Expr::accept(Visitor& v)
{
	v.accept(*this);
}

void Stmt::accept(Visitor& v)
{
	v.accept(*this);
}

