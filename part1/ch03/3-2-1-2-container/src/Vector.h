/*
 * Vector.h
 *
 *  Created on: 2016/03/21
 *      Author: sasaki
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
private:
	double*	elem;
	int		sz;
public:
	Vector(int s) :elem{new double[s]}, sz{s}
	{
		for( int i = 0 ; i != s ; ++i ) elem[i] = 0;
	}
	~Vector() { delete[] elem; }
	double& operator[](int i) { return elem[i]; }
	int size() const { return sz; }
};



#endif /* VECTOR_H_ */
