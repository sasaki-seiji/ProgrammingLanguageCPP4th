/*
 * decltype.cpp
 *
 *  Created on: 2016/04/11
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

template<typename T, int ROWS=5, int COLS=5>
class Matrix {
public:
	Matrix() :vals(ROWS*COLS, T{}) { };
	int	rows() const { return ROWS; }
	int cols() const { return COLS; }
	T& operator()(int i, int j) { return vals[i*COLS+j]; }
	const T& operator()(int i, int j) const { return vals[i*COLS+j]; }
private:
	vector<T> vals;
};

template<typename T, typename U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matrix<decltype(T{}+U{})>;

template<typename T, typename U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matrix<decltype(T{}+U{})>
{
	Matrix<decltype(T{}+U{})> res;
	for (int i=0; i!=a.rows(); ++i)
		for (int j=0; j!=a.cols(); ++j)
			res(i,j) += a(i,j) + b(i,j);
	return res;
}

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& m)
{
	for (int i = 0; i != m.rows(); ++i) {
		os << "{ ";
		for (int j = 0; j != m.cols(); ++j )
			os << m(i,j) << ", ";
		os << "}\n";
	}
	return os;
}

int main()
{
	Matrix<float> a;
	Matrix<double> b;

	for (int i = 0; i != a.rows(); ++i)
		for (int j = 0 ; j != a.cols(); ++j ) {
			a(i, j) = i ;
			b(i, j) = j;
		}
	auto res = a + b;
	cout << res;
}

