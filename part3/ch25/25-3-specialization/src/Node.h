/*
 * Node.h
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#ifndef NODE_H_
#define NODE_H_


class Node {
public:
	virtual const char* what() const = 0;
	virtual ~Node() { }
};

class Expr : public Node {
public:
	const char* what() const override { return "Expr"; }
};

class Stmt : public Node {
public:
	const char* what() const override { return "Stmt"; }
};

#endif /* NODE_H_ */
