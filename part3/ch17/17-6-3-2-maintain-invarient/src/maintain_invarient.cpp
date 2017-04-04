/*
 * maintain_invarient.cpp
 *
 *  Created on: 2016/08/01
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

struct Z {
	vector<int> elem;
	int my_favorite;
	int* largest;
};


// add util

ostream& operator<<(ostream& os, const vector<int>& v)
{
	os << "[ ";
	for (auto x : v)
		os << x << ", ";
	os << "]";
	return os;
}

void print(const Z& z)
{
	cout << ".elem: " << z.elem << " .my_favorite: " << z.my_favorite
			<< " .largest: " << z.largest << '\n';
}

// add main

int main()
{
	Z v0;
	cout << "Z v0; "; print(v0);

	Z val {{1,2,3},1,&val.elem[2]};
	cout << "Z val {{1,2,3},1,&val.elem[2]}; "; print(val);

	Z v2 = val;
	cout << "Z v2 = val; "; print(v2);

	Z v3 = move(val);
	cout << "Z v3 = move(val); "; print(v3);
	cout << "val: "; print(val);
}
