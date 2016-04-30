/*
 * allocate_memory.cpp
 *
 *  Created on: 2016/04/30
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

void f()
{
	vector<char*> v;
	try {
		for (;;) {
			char* p = new char[10000];
			v.push_back(p);
			p[0] = 'x';
		}
	}
	//catch (bad_alloc) {
	catch (bad_alloc&) {
		// Catching by reference is recommended 'bad_alloc'

		cerr << "Memory exhausted!\n";
	}
}

int main()
{
	f();
}
