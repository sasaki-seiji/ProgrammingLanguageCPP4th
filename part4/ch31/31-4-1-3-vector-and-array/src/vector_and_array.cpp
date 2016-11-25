/*
 * vector_and_array.cpp
 *
 *  Created on: 2016/11/26
 *      Author: sasaki
 */


#include <array>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX=5;

void read()
{
	array<int,MAX> a;
	for (auto& x : a)
		//cin.get(x);
		cin >> x;

	for (auto x : a)
		cout << x << endl;
}

void read_vec()
{
	vector<int> a;
	for (int x; cin >> x; )
		a.push_back(x);

	for (auto x : a)
		cout << x << endl;
}

int main()
{
	read();
	read_vec();
}
