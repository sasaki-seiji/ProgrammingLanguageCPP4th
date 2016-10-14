/*
 * Tuple.h
 *
 *  Created on: 2016/10/13
 *      Author: sasaki
 */

#ifndef TUPLE_H_
#define TUPLE_H_

#include <ostream>
#include "select.h"

template<typename T1=Nil, typename T2=Nil, typename T3=Nil, typename T4=Nil>
struct Tuple : Tuple<T2,T3,T4> {
	T1 x;

	using Base = Tuple<T2,T3,T4>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }

	Tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
		: Base{t2,t3,t4}, x{t1} { }
};

template<>
struct Tuple<> { Tuple() { } };

template<typename T1>
struct Tuple<T1> : Tuple<> {
	T1 x;

	using Base = Tuple<>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }

	Tuple(const T1& t1)
		: Base{}, x{t1} { }

};

template<typename T1, typename T2>
struct Tuple<T1,T2> : Tuple<T2> {
	T1 x;

	using Base = Tuple<T2>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }

	Tuple(const T1& t1, const T2& t2)
		: Base{t2}, x{t1} { }
};

template<typename T1, typename T2, typename T3>
struct Tuple<T1,T2,T3> : Tuple<T2,T3> {
	T1 x;

	using Base = Tuple<T2,T3>;
	Base* base() { return static_cast<Base*>(this); }
	const Base* base() const { return static_cast<const Base*>(this); }

	Tuple(const T1& t1, const T2& t2, const T3& t3)
		: Base{t2,t3}, x{t1} { }
};

template<typename T1, typename T2, typename T3, typename T4>
void print_elements(std::ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
	os << t.x << ", ";
	print_elements(os, *t.base());
}

template<typename T1, typename T2, typename T3>
void print_elements(std::ostream& os, const Tuple<T1,T2,T3>& t)
{
	os << t.x << ", ";
	print_elements(os, *t.base());
}

template<typename T1, typename T2>
void print_elements(std::ostream& os, const Tuple<T1,T2>& t)
{
	os << t.x << ", ";
	print_elements(os, *t.base());
}

template<typename T1>
void print_elements(std::ostream& os, const Tuple<T1>& t)
{
	os << t.x;
}

template<>
void print_elements(std::ostream& os, const Tuple<>& t)
{
	os << "";
}

template<typename T1, typename T2, typename T3, typename T4>
std::ostream& operator<<(std::ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
	os << "{ ";
	print_elements(os,t);
	os << " }";
	return os;
}

template<typename Ret, int N>
struct getNth {
	template<typename T>
	static Ret& get(T& t)
	{
		return getNth<Ret,N-1>::get(*t.base());
	}
	template<typename T>
	static const Ret& get(const T& t)
	{
		return getNth<Ret,N-1>::get(*t.base());
	}
};

template<typename Ret>
struct getNth<Ret,0> {
	template<typename T>
	static Ret& get(T& t)
	{
		return t.x;
	}
	template<typename T>
	static const Ret& get(const T& t)
	{
		return t.x;
	}
};

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
{
	return getNth<Select<N, T1, T2, T3, T4>, N>::get(t);
}

template<int N, typename T1, typename T2, typename T3, typename T4>
const Select<N, T1, T2, T3, T4>& get(const Tuple<T1, T2, T3, T4>& t)
{
	return getNth<Select<N, T1, T2, T3, T4>, N>::get(t);
}

template<typename T1, typename T2, typename T3, typename T4>
Tuple<T1, T2, T3, T4> make_tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
{
	return Tuple<T1, T2, T3, T4>{t1, t2, t3, t4};
}

template<typename T1, typename T2, typename T3>
Tuple<T1, T2, T3> make_tuple(const T1& t1, const T2& t2, const T3& t3)
{
	return Tuple<T1, T2, T3>{t1, t2, t3};
}

template<typename T1, typename T2>
Tuple<T1, T2> make_tuple(const T1& t1, const T2& t2)
{
	return Tuple<T1, T2>{t1, t2};
}

template<typename T1>
Tuple<T1> make_tuple(const T1& t1)
{
	return Tuple<T1>{t1};
}

#endif /* TUPLE_H_ */
