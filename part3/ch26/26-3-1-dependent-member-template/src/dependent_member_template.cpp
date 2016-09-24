/*
 * dependent_member_template.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class Pool {
public:
	template<typename T> T* get() { return new T; }
	template<typename T> void release(T* p) { delete p; }
};

template<typename Alloc>
void f(Alloc& all)
{
	//int* p1 = all.get<int>();
		// error: expected primary-expression before 'int'
	int* p2 = all.template get<int>();

	*p2 = 100;
	cout << "p2: " << p2 << ", *p2: " << *p2 << '\n';

	//all.release(p1);
	all.release(p2);
}

void user(Pool& pool)
{
	f(pool);
}

// add main

int main()
{
	Pool pool;
	user(pool);
}
