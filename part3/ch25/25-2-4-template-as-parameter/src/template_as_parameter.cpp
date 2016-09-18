/*
 * template_as_parameter.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */

#include <vector>
#include <string>
#include <set>
using namespace std;

template<typename T, template<typename> class C>
class Xrefd {
	C<T> mems;
	C<T*> refs;
};

template<typename T>
using My_vec = vector<T>;

struct Entry {
	string name;
	int id;
};

Xrefd<Entry,My_vec> x1;


template<typename T>
class My_container {

};

struct Record {
	int id;
	string name;
	string addr;
};

Xrefd<Record,My_container> x2;

template<typename C, typename C2>
class Xrefd2 {
	C mems;
	C2 refs;
};
Xrefd2<vector<Entry>, set<Entry*>> x;

// add main

int main()
{

}
