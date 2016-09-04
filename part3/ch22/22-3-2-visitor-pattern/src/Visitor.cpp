/*
 * Visitor.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Visitor.h"

void Node_counter::accept(Expr&)
{
	++cexpr;
}

void Node_counter::accept(Stmt&)
{
	++cstmt;
}

Node_counter::Node_counter()
	: cexpr{0}, cstmt{0}
{
}

void Node_counter::clear()
{
	cexpr = cstmt = 0;
}

