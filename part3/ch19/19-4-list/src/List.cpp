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

