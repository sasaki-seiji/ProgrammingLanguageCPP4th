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
	Vector(int s);
	~Vector();

	Vector(const Vector& a);
	Vector& operator=(const Vector& a);

	double& operator[](int i);
	const double& operator[](int i) const;

	int size() const;
};


#endif /* VECTOR_H_ */
