/*
 * list_conatainer.h
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef LIST_CONTAINER_H_
#define LIST_CONTAINER_H_

#include <list>
#include <initializer_list>

#include "container.h"

class List_container : public Container {
	std::list<double> ld;
public:
	List_container() {}
	List_container(std::initializer_list<double> il) : ld {il} { }
	~List_container() { }

	double& operator[](int i);
	int size() const { return ld.size(); }
};

#endif /* LIST_CONTAINER_H_ */
