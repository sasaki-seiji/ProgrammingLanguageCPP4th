/*
 * non_error_exception.cpp
 *
 *  Created on: 2017/03/09
 *      Author: sasaki
 */

#include <string>
#include <iostream>
using namespace std;

struct Tree {
	string str;
	Tree *left, *right;
};

void fnd(Tree* p, const string& s)
{
	if (s == p->str) throw p;
	if (p->left) fnd(p->left, s);
	if (p->right) fnd(p->right, s);
}

Tree* find(Tree* p, const string& s)
{
	try {
		fnd(p, s);
	}
	catch (Tree* q) {
		return q;
	}
	return 0;
}

int main()
{
	Tree *node11 = new Tree {"abc"};
	Tree *node12 = new Tree {"ABC"};
	Tree *node1 = new Tree {"alpha", node11, node12};
	Tree *node21 = new Tree {"012"};
	Tree *node22 = new Tree {"789"};
	Tree *node2 = new Tree {"digit", node21, node22};
	Tree *root = new Tree {"root", node1, node2};

	Tree *found = find(root, "012");
	if (found) cout << "found: " << found->str << endl;
	else cout << "not found: " << "012" << endl;

	found = find(root, "xyz");
	if (found) cout << "found: " << found->str << endl;
	else cout << "not found: " << "xyz" << endl;
}

