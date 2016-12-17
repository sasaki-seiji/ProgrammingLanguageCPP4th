/*
 * type_index.cpp
 *
 *  Created on: 2016/12/17
 *      Author: sasaki
 */


#include <typeindex>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	unordered_map<type_index,const type_info*> types;

	string s = "str";

	types[type_index{typeid(10)}] = &typeid(10);
	types[type_index{typeid(s)}] = &typeid(s);

	int x = 100;
	string s2 = "a little longer string";

	const type_info* p;
	p = types.at(type_index{typeid(x)});
	cout << p->name() << endl;
	p = types.at(type_index{typeid(s2)});
	cout << p->name() << endl;

}
