/*
 * user.cpp
 *
 *  Created on: 2016/09/19
 *      Author: sasaki
 */


#include "Vector.h"
#include "Shape.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

Vector<int> vi;
Vector<Shape*> vps;
Vector<string> vs;
Vector<char*> vpc;
Vector<Node*> vpn;

Vector<void*> vpv;

// add main

int main()
{
	Vector<int> vi2 = {12, 23, 34, 45, 56};
	for (auto x : vi2)
		cout << x << ' ';
	cout << '\n';

	Vector<Shape*> vps2 = { new Circle(0, -2, 5), new Rectangle(1, -2, 3, 4),
							new Circle(-3, 3, 4), new Rectangle(-3, 3, 2, 2) };
	for (auto x : vps2)
		x->draw();

	Vector<string> vs2 = {"this", "is", "a", "string"};
	for (auto x : vs2)
		cout << x << '|';
	cout << '\n';

	Vector<char*> vpc2 = {"this", "is", "a", "char*"};
	for (auto x : vpc2)
		cout << x << '|';
	cout << '\n';

	Vector<Node*> vpn2 = { new Expr, new Stmt, new Stmt, new Expr };
	for (auto x : vpn2)
		cout << x->what() << ' ';
	cout << '\n';

}

