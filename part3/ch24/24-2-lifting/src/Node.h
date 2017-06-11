/*
 * Node.h
 *
 *  Created on: 2017/06/11
 *      Author: sasaki
 */

#ifndef NODE_H_
#define NODE_H_


struct Node { Node* next; int data; };
struct Node_iter { Node* pos; };

//Node_iter operator++(Node_iter& p) { return p.pos = p.pos->next; }
	// error: could not convert '(p.Node_iter::pos = p.Node_iter::pos->Node::next)' from 'Node*' to 'Node_iter'
Node_iter operator++(Node_iter& p) { p.pos = p.pos->next; return p; }
int operator*(Node_iter p) { return p.pos->data; }
bool operator!=(Node_iter p, Node_iter q) { return p.pos != q.pos; }




#endif /* NODE_H_ */
