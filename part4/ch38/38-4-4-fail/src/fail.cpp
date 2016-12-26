/*
 * fail.cpp
 *
 *  Created on: 2016/12/26
 *      Author: sasaki
 */


#include <iostream>
using namespace std;

int main()
{
	for (int x; !(cin>>x).fail(); ) {
		cout << x << endl;
	}
}
