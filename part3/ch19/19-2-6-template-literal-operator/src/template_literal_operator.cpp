/*
 * template_literal_operator.cpp
 *
 *  Created on: 2016/08/16
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<char...>
constexpr int operator"" _b3();

constexpr int ipow(int x, int n)
{
	return n>0?x*ipow(x,n-1):1;
}

template<char...> struct helper; // unused primary template

template<char c>
struct helper<c> {	// specialized for 1-digits
	static_assert('0'<=c&&c<'3', "not a tenary digit");
	static constexpr int value() { return c-'0'; }
};

template<char c, char... tail>
struct helper<c, tail...> {	// specialized for 2 or more digits
	static_assert('0'<=c&&c<'3', "not a ternary digit");
	static constexpr int value() {
		return (c-'0')*ipow(3,sizeof...(tail)) + helper<tail...>::value();
	}
};

template<char... chars>
constexpr int operator"" _b3()
{
	return helper<chars...>::value();
}

constexpr int i1 = 201_b3;
//constexpr int i2 = 241_b3;
	//error: static assertion failed: not a ternary digit

namespace Numerics {
	class Bignum {
		string str;
	public:
		Bignum(const char* p) : str{p} { }
		friend ostream& operator<<(ostream&, const Bignum&);
	};
	ostream& operator<<(ostream& os, const Bignum& bn)
	{
		os << "Bignum(" << bn.str << "x)";
		return os;
	}
	namespace literals {
		Bignum operator"" x(char const* p)
		{
			return Bignum{p};
		}
	}
}

using namespace Numerics;
using namespace Numerics::literals;
Bignum bnum = 123456789012345678901234567890x;

// add main

int main()
{
	cout << "i1: " << i1 << '\n';
	cout << "bnum: " << bnum << '\n';
}

