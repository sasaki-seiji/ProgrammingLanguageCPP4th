/*
 * Node.h
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#ifndef NODE_H_
#define NODE_H_

class Visitor;

class Node {
public:
	virtual void accept(Visitor&) = 0;

	virtual ~Node() { }
};

class Expr : public Node {
public:
	void accept(Visitor&) override;
};

class Stmt : public Node {
public:
	void accept(Visitor&) override;
};

#endif /* NODE_H_ */
