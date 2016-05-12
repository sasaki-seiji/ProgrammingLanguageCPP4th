/*
 * argument_passing.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

int* find(int* first, int* last, int v)
{
	while (first!=last && *first!=v)
		++first;
	return first;
}

void g(int* p, int* q)
{
	int* pp = find(p, q, 'x');
	cout << ( (pp == q) ? "not found: 'x'" : "found: 'x'" ) << '\n';
}

int main()
{
	int	v1[] = { 10, 'a', 'b', 'c', 100, 'x', 'y' };
	int v2[] = { 10, 100, 1000, 10000 };
	g(v1, v1 + sizeof(v1)/sizeof(*v1));
	g(v2, v2 + sizeof(v2)/sizeof(*v2));
}
