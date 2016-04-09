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
	int		space;
public:
	Vector() :elem{ nullptr }, sz{ 0 }, space{ 0 } { }
	Vector(int s);	// 2016.03.26 add
	Vector(std::initializer_list<double> lst);
	Vector(const Vector&src);
	~Vector() { delete[] elem; }
	Vector& operator=(const Vector& src);
	double& operator[](int i) { return elem[i]; }
	int size() const { return sz; }
	void push_back(double);
};

#endif /* VECTOR_H_ */
