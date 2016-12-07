/*
 * shared_ptr.cpp
 *
 *  Created on: 2016/12/07
 *      Author: sasaki
 */


#include <memory>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
	string name;
	vector<shared_ptr<Node>> edges;
	~Node() { cout << "destructing " << name << endl; }
};

vector<shared_ptr<Node>> make_network()
{
	shared_ptr<Node> n11 {new Node {"n11"}};
	shared_ptr<Node> n12 {new Node {"n12"}};
	shared_ptr<Node> n21 {new Node {"n21"}};
	shared_ptr<Node> n22 {new Node {"n22"}};
	shared_ptr<Node> n23 {new Node {"n23"}};
	shared_ptr<Node> n31 {new Node {"n31"}};
	shared_ptr<Node> n32 {new Node {"n32"}};
	shared_ptr<Node> n33 {new Node {"n33"}};
	shared_ptr<Node> n34 {new Node {"n34"}};

	vector<shared_ptr<Node>> top;
	top.push_back(n11);
	top.push_back(n12);

	n11->edges.push_back(n21);
	n11->edges.push_back(n22);
	n12->edges.push_back(n22);
	n12->edges.push_back(n23);

	n21->edges.push_back(n31);
	n21->edges.push_back(n32);
	n22->edges.push_back(n32);
	n22->edges.push_back(n33);
	n23->edges.push_back(n34);

	return top;
}

struct S {
	int i;
	string s;
	double d;

	// 2016.12.07 add
	S(int ii, const string& ss, double dd) : i{ii}, s{ss}, d{dd} { }
		// error: no matching function for call to 'S::S(int, const char [13], double)'
};

int main()
{
	vector<shared_ptr<Node>> top = make_network();
	cout << "-- deleting n12: " << endl;
	top.pop_back();
	cout << "-- deleting n11: " << endl;
	top.pop_back();

	auto p = make_shared<S>(1,"Ankh Morpork",4.65);
	cout << "p->i: " << p->i << ", p->s: " << p->s << ", p->d: " << p->d << endl;
}
