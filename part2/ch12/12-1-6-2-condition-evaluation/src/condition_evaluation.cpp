/*
 * condition_evaluation.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

constexpr int f(int x, int y, int z)
{
	return x+y+z;
}
constexpr int x = 10;
constexpr int y = 20;
constexpr int z = 30;

constexpr int low = 0;
constexpr int high = 99;

constexpr int check(int i)
{
	return (low<=i && i<high) ? i : throw out_of_range("check() faild");
}

constexpr int val0 = check(50);
constexpr int val1 = check(f(x, y, z));
//constexpr int val2 = check(200);
	// in constexpr expansion of 'check(200)'


int main()
{
	cout << "val0: " << val0 << '\n';
	cout << "val1: " << val1 << '\n';
}
