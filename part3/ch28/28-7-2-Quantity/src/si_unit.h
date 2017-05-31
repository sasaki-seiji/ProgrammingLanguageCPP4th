/*
 * si_uinit.h
 *
 *  Created on: 2017/05/31
 *      Author: sasaki
 */

#ifndef SI_UNIT_H_
#define SI_UNIT_H_

template<int M, int K, int S>
struct Unit {
	enum { m=M, kg=K, s=S };
};

using M = Unit<1,0,0>;
using Kg = Unit<0,1,0>;
using S = Unit<0,0,1>;
using MpS = Unit<1,0,-1>;
using MpS2 = Unit<1,0,-2>;

template<typename U1, typename U2>
struct Uplus {
	using type = Unit<U1::m+U2::m, U1::kg+U2::kg, U1::s+U2::s>;
};

template<typename U1, typename U2>
using Unit_plus = typename Uplus<U1,U2>::type;


template<typename U1, typename U2>
struct Uminus {
	using type = Unit<U1::m-U2::m, U1::kg-U2::kg, U1::s-U2::s>;
};

template<typename U1, typename U2>
using Unit_minus = typename Uminus<U1,U2>::type;

template<typename U>
struct Quantity {
	double val;
	explicit constexpr Quantity(double d) : val{d} { }
};

template<typename U>
Quantity<U> operator+(Quantity<U> x, Quantity<U> y)
{
	return Quantity<U>{x.val+y.val};
}

template<typename U>
Quantity<U> operator-(Quantity<U> x, Quantity<U> y)
{
	return Quantity<U>{x.val-y.val};
}

template<typename U1, typename U2>
Quantity<Unit_plus<U1,U2>> operator*(Quantity<U1> x, Quantity<U2> y)
{
	return Quantity<Unit_plus<U1,U2>>{x.val*y.val};
}

template<typename U1, typename U2>
Quantity<Unit_minus<U1,U2>> operator/(Quantity<U1> x, Quantity<U2> y)
{
	return Quantity<Unit_minus<U1,U2>>{x.val/y.val};
}

template<typename U>
Quantity<U> operator*(Quantity<U> x, double y)
{
	return Quantity<U>{x.val*y};
}

template<typename U>
Quantity<U> operator*(double x, Quantity<U> y)
{
	return Quantity<U>{x*y.val};
}



#endif /* SI_UNIT_H_ */
