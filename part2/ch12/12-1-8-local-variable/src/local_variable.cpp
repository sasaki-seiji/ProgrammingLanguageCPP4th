/*
 * local_variable.cpp
 *
 *  Created on: 2016/05/05
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

void f(int a)
{
	cout << "-- f(" << a << ") --\n";

	while (a--) {
		static int n = 0;
		int x = 0;

		cout << "n == " << n++ << ", x == " << x++ << '\n';
	}
}

int fn(int n)
{
	cout << "-- fn(" << n << ") --\n";

	static int n1 = n;
	//static int n2 = fn(n-1)+1;
		// hang up
		// in Ubuntu:
		// terminate called after throwing an instance of '__gnu_cxx::recursive_init_error'
		//    what():  std::exception

	cout << "n1 = " << n1 << '\n';
	//cout << "n2: " << n2 << '\n';
	return n;
}

int main()
{
	f(3);
	fn(3);
}
