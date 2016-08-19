/*
 * List2.cpp
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#include "List2.h"

int* List2_iterator::next()
{
	if (!cur) return nullptr;

	int *p = &cur->value;
	cur = cur->next;
	return p;
}


List2* List2::add_head(List2* link)
{
	List2 **p_next = &link->next;
	while (*p_next)
		p_next = &(*p_next)->next;
	*p_next = this;
	return link;
}

List2* List2::add_tail(List2* link)
{
	List2 **p_next = &this->next;
	while (*p_next)
		p_next = &(*p_next)->next;
	*p_next = link;
	return link;

}

