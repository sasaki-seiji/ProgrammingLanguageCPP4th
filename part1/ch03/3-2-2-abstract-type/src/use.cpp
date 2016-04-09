/*
 * use.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "container.h"
#include "vector_container.h"
#include "list_container.h"

void use(Container& c)
{
	const int sz = c.size();

	for( int i = 0 ; i != sz; ++i )
		cout << c[i] << '\n';
}

void g()
{
	Vector_container vc(10);
	vc[0] = 1.2; vc[5] = 2.3;	// 2016.03.26 add
	use(vc);
}

void h()
{
	List_container lc = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	use(lc);
}

int main()
{
	g();
	h();
}
