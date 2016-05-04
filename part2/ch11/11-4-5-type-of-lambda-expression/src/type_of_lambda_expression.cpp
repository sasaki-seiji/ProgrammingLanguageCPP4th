/*
 * type_of_lambda_expression.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <functional>
#include <cmath>
#include <iostream>
using namespace std;

void f(string& s1, string& s2)
{
	//auto rev = [&rev](char* b, char*e) { if (1 < e-b) { swap(*b, *--e); rev(++b, e); } };
		// use of 'rev' before deduction of 'auto'	type_of_lambda_expression.cpp	/11-4-5-type-of-lambda-expression/src	行 14	C/C++ 問題
	function<void(char*,char*)> rev =
		//[](char* b, char* e) { if (1 < e-b) { swap(*b, *--e); rev(++b, e); } };
		[&rev](char* b, char* e) { if (1 < e-b) { swap(*b, *--e); rev(++b, e); } };
			// 'rev' is not captured

	rev(&s1[0], &s1[0]+s1.size());
	rev(&s2[0], &s2[0]+s2.size());
}

void g(string& s1, string& s2)
{
	auto rev = [](char* b, char* e) { while (1 < e-b) swap(*b++, *--e); };

	rev(&s1[0], &s1[0]+s1.size());
	rev(&s2[0], &s2[0]+s2.size());
}

int main()
{
	string s1 {"string-1"}, s2 {"string-2"};

	f(s1, s2);
	cout << "s1:" << s1 << '\n';
	cout << "s2:" << s2 << '\n';

	g(s1, s2);
	cout << "s1:" << s1 << '\n';
	cout << "s2:" << s2 << '\n';

	double (*p1)(double) = [](double a) { return sqrt(a); };
	double (*p2)(double) = [&](double a) { return sqrt(a); };
	//double (*p3)(int) = [](double a) { return sqrt(a); };
		// invalid user-defined conversion from 'main()::<lambda(double)>' to 'double (*)(int)' [-fpermissive]

	cout << "p1(3.5)->" << p1(3.5) << '\n';
	cout << "p2(3.5)->" << p2(3.5) << '\n';
}
