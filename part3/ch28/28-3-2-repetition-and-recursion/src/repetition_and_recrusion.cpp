/*
 * repetition_and_recrusion.cpp
 *
 *  Created on: 2016/10/07
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

template<int N>
constexpr int fac()
{
	return N*fac<N-1>();
}

template<>
constexpr int fac<1>()
{
	return 1;
}

constexpr int x5 = fac<5>();

constexpr int fac2(int i)
{
	return (i<2)?1:i*fac2(i-1);
}

constexpr int x6 = fac2(6);

// add main
int main()
{
	cout << "x5: " << x5 << '\n';
	cout << "x6: " << x6 << '\n';
}
