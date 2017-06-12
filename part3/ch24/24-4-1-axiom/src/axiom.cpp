/*
 * axiom.cpp
 *
 *  Created on: 2016/10/23
 *      Author: sasaki
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
bool Copy_equality(T x)
{
	return T{x}==x;
}

template<typename T>
bool Copy_assign_equality(T x, T& y)
{
	return (y=x, y==x);
}

// temporal impl
template<typename T>
bool can_destroy(T& x) { return true; }

template<typename T>
bool Move_effect(T x, T& y)
{
	return (x==y ? (x==T{std::move(y)}) : true) && can_destroy(y);
}

template<typename T>
bool Move_assign_effect(T x, T& y, T& z)
{
	return (y==z ? (x=std::move(y), x==z) : true) && can_destroy(y);
}


// add main

int main()
{
	cout << boolalpha;
	cout << "Copy_equality(int:10) :" << Copy_equality(10) << '\n';
	cout << "Copy_equality(string:\"abc\"): " << Copy_equality(string{"abc"}) << '\n';

	vector<int> vi{1,2,3},vo;
	cout << "Copy_assign_equality(vector:{1,2,3}, vector&): " << Copy_assign_equality(vi, vo) << '\n';

	string	s1{"abc"}, s2{"abc"};
	cout << "Move_effect(string:\"abc\",string&:\"abc\"): " << Move_effect(s1,s2) << '\n';
	cout << "after moved - s2: " << s2 << '\n';

	string	s3, s4{"abc"}, s5{"abc"};
	cout << "Move_assign_effect(string,string&:\"abc\",string&:\"abc\"): "
			<< Move_assign_effect(s3,s4,s5) << '\n';
	cout << "after moved - s4: " << s4 << '\n';
}

