/*
 * Link.h
 *
 *  Created on: 2016/07/18
 *      Author: sasaki
 */

#ifndef LINK_H_
#define LINK_H_

struct Link {
	Link* pre;
	Link* suc;
	int data;

	Link * insert(int x)
	{
		return pre = new Link{pre, this, x};
	}

	void remove()
	{
		if (pre) pre->suc = suc;
		if (suc) suc->pre = pre;
		delete this;
	}
};

#endif /* LINK_H_ */
