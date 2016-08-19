/*
 * List.cpp
 *
 *  Created on: 2016/08/19
 *      Author: sasaki
 */

#include "List.h"

int* List_iterator::next()
{
	if (!cur) return nullptr;

	int *p = &cur->value;
	cur = cur->next;
	return p;
}


List* List::add_head(List* link)
{
	link->next = this;
	return link;
}

List* List::add_tail(List* link)
{
	List **p_next = &this->next;
	while (*p_next)
		p_next = &(*p_next)->next;
	*p_next = link;
	return link;

}
