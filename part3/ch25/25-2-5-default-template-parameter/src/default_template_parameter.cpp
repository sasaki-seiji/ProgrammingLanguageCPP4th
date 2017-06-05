/*
 * default_template_parameter.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */


#include "Map.h"
#include <string>
#include <iostream>
#include <typeinfo>
//#include <cstring>
#include <strings.h> // for Linux
using namespace std;

Map<string,int> m1;
Map<string,int,less<string>> m2;

struct No_case {
	bool operator()(const string& a, const string& b)
	{
		//return stricmp(a.c_str(), b.c_str()) < 0;
		return strcasecmp(a.c_str(), b.c_str()) < 0; // for Linux
	}
};
Map<string,int,No_case> m3;

struct Complex_compare {
	string	str;
	int		i;
	bool	operator()(const string& a, const string& b)
	{
		return a < b;
	}
};
Map<string,int,Complex_compare> m {Complex_compare{"French",3}};

void test_Map()
{
	cout << "-- test_Map() --\n";

	cout << "typeid(Map<string,int>): " << typeid(m1).name() << '\n';
	cout << "typeid(Map<string,int,less<string>>): " << typeid(m2).name() << '\n';
	cout << "typeid(Map<string,int,No_case>): " << typeid(m3).name() << '\n';
	cout << "typeid(Map<string,int,Complex_compare>): " << typeid(m).name() << '\n';
}

//void f1(int x = 0, int y);
	// error: default argument missing for parameter 2 of 'void f1(int, int)'
void f2(int x = 0, int y = 0);

//template<typename T1 = int, typename T2>
//class X1 { };
	// error: no default argument for 'T2'
template<typename T1 = int, typename T2 = double>
class X2 {
	T1 d1;
	T2 d2;
public:
	X2(const T1& t1 ={}, const T2& t2 ={}) :d1{t1}, d2{t2} { }
	T1 value1() const { return d1; }
	T2 value2() const { return d2; }
};
//X2<,float> v1;
	// error: template argument 1 is invalid
X2<float> v2;

void test_default_template_param()
{
	cout << "-- test_default_template_param() --\n";

	//f2(,2);
		// error: expected primary-expression before ',' token
	f2(2);

	cout << v2.value1() << '\n';
	cout << v2.value2() << '\n';
}

// add undef

void f2(int x, int y)
{
	cout << "f2(" << x << "," << y << ")\n";
}

// add main

int main()
{
	test_Map();
	test_default_template_param();
}
