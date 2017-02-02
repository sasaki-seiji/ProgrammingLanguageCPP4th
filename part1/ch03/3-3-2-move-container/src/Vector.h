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

	// move
	Vector(Vector&& a);
	Vector& operator=(Vector&& a);

	double& operator[](int i);
	const double& operator[](int i) const;

	int size() const;
};

class Vector_size_mismatch { };

Vector operator+(const Vector& a, const Vector& b);

#endif /* VECTOR_H_ */
