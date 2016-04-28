/*
 * reference_argument.cpp
 *
 *  Created on: 2016/04/28
 *      Author: sasaki
 */


//#include <complex>
#include <iostream>
using namespace std;

template<typename T> class complex {
public:
	constexpr complex(T re = 0, T im = 0) :r{re}, i{im} { }
	template<typename U> constexpr complex(const complex<U>&);
//	template<typename U> explicit constexpr complex(const complex<U>&);

	//constexpr T real() {return r;}
	constexpr T real() const {return r;}
		// Invalid arguments '	Candidates are:	float real() void real(float)'
	void real(T);
	//constexpr T imag() {return i;}
	constexpr T imag() const {return i;}
		// Invalid arguments 'Candidates are: float imag() void imag(float)'
	void imag(T);

	complex<T>& operator=(T);
	complex<T>& operator+=(T);
	// ...

private:
	T r, i;
};

template<typename T>
ostream& operator<<(ostream& os, const complex<T>& c)
{
	os << '(' << c.real() << ',' << c.imag() << ')';
	return os;
}

template<> class complex<double> {
public:
	constexpr complex(double re = 0, double im = 0) :r{re}, i{im} { }
	constexpr complex(const complex<float>& z) : r{z.real()}, i{z.imag()} { }
	explicit constexpr complex(const complex<long double>&);

	constexpr double real() const {return r;}
	void real(double);
	constexpr double imag() const {return i;}
	void imag(double);

	complex<double>& operator=(double);
	complex<double>& operator+=(double);
	// ...
private:
	double r,i;
};

constexpr complex<float> z1{1,2};
constexpr double re = z1.real();
constexpr double im = z1.imag();
constexpr complex<double> z2 {re,im};
constexpr complex<double> z3 {z1};

int main()
{
	cout << "z1: " << z1 << '\n';
	cout << "re: " << re << '\n';
	cout << "im: " << im << '\n';
	cout << "z2: " << z2 << '\n';
	cout << "z3: " << z3 << '\n';
}
