/*
 * composite_operation.h
 *
 *  Created on: 2016/11/23
 *      Author: sasaki
 */

#ifndef COMPOSITE_OPERATION_H_
#define COMPOSITE_OPERATION_H_


#include "Matrix.h"

using Mat2d = Matrix<double,2>;
using Vec = Matrix<double,1>;

struct MVmul {
	const Mat2d& m;
	const Vec& v;

	MVmul(const Mat2d& mm, const Vec& vv) : m{mm}, v{vv} { }

	//operator Vec();
};

inline MVmul operator*(const Mat2d& mm, const Vec& vv)
{
	return MVmul(mm,vv);
}

struct MVmulVadd {
	const Mat2d& m;
	const Vec& v;
	const Vec& v2;

	MVmulVadd(const MVmul& mv, const Vec& vv) : m{mv.m}, v{mv.v}, v2{vv} { }

	// 2016.11.23 del : batting with Vec::Vec(const MVmulVadd&)
	//operator Vec();
		// C:\books\ProgrammingLanguageCPP4th\part3\ch29\29-5-4-composite-operation\Debug/../src/main.cpp:23: undefined reference to `MVmulVadd::operator Matrix<double, 1ull>()'

};

inline MVmulVadd operator+(const MVmul& mv, const Vec& vv)
{
	return MVmulVadd(mv,vv);
}

void mul_add_and_assign(Vec*, const Mat2d*, const Vec*, const Vec*);

template<>
class Matrix<double,1>
{
public:
	explicit Matrix(size_t n) : elems(n) { }

	Matrix(const MVmulVadd& m)
		:elems(m.v.size())
	{
		mul_add_and_assign(this, &m.m, &m.v, &m.v2);
	}

	Matrix& operator=(const MVmulVadd& m)
	{
		mul_add_and_assign(this, &m.m, &m.v, &m.v2);
		return *this;
	}

	Matrix(std::initializer_list<double> init)
		:elems(init.size())
	{
		copy(init.begin(), init.end(), elems.begin());
	}

	size_t size() const { return elems.size(); }
	double& operator()(size_t i) { return elems[i]; }
	double operator()(size_t i) const { return elems[i]; }

private:
	std::vector<double> elems;
};

std::ostream& operator<<(std::ostream&, const Vec&);

#endif /* COMPOSITE_OPERATION_H_ */
