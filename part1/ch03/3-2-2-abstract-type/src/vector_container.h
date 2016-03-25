/*
 * vector_container.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#ifndef VECTOR_CONTAINER_H_
#define VECTOR_CONTAINER_H_

#include <initializer_list>
#include "Vector.h"

class Vector_container : public Container {
	Vector v;
public:
	Vector_container(int s) : v(s) {}
	~Vector_container() {}

	double& operator[](int i) { return v[i]; }
	int size() const { return v.size(); }
};

#endif
