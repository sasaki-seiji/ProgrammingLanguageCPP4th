/*
 * goto_statement.cpp
 *
 *  Created on: 2016/04/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

const int ncol = 3;
int nm[][ncol] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
};

void do_something(int n, int m, int a)
{
	for (int i=0; i!=n; ++i)
		for (int j=0; j!=m; ++j)
			if (nm[i][j] == a)
				goto found;

	cout << "not found: " << a << '\n';
	return ;
found:
	cout << "found: " << a << '\n';
}

int main()
{
	do_something(3, 3, 5);
	do_something(3, 3, -1);
}
