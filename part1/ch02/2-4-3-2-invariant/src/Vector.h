/*
 * Vector.h
 *
 *  Created on: 2016/03/20
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_


class Vector {
public:
	Vector(int s);
	double& operator[](int i);
	int size();
private:
	double* elem;
	int sz;
};




#endif /* VECTOR_H_ */
