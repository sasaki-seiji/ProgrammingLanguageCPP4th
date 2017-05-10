/*
 * abuse_rtti_dynamic_cast.cpp
 *
 *  Created on: 2016/09/05
 *      Author: sasaki
 */

#include <iostream>
#include <vector>
using namespace std;

class Object {
public:
	virtual ~Object() { }
};

class Container : public Object {
public:
	void put(Object* p) { v.push_back(p); }
	Object* get() { Object *p = v.back(); v.pop_back(); return p; }
private:
	vector<Object*> v;
};

class Ship : public Object { };

Ship* f(Ship* ps, Container* c)
{
	cout << "-- f(Ship*, Container*) --\n";

	c->put(ps);

	Object* p = c->get();
	if (Ship* q = dynamic_cast<Ship*>(p)) {
		return q;
	}
	else {
		cout << "not ship object\n";
	}
	return nullptr;
}

Ship* f(Ship* ps, vector<Ship*>& c)
{
	cout << "-- f(Ship*, vector<Ship*>&) --\n";

	c.push_back(ps);

	Ship* p = c.back();
	c.pop_back();
	return p;
}

// add main

int main()
{
	Container c;
	Ship s;
	Ship* p = f(&s, &c);
	cout << boolalpha;
	cout << "f(&s,Container*) == &s ? " << (p == &s) << '\n';

	vector<Ship*> v;
	Ship* q = f(&s, v);
	cout << "f(&s, vector<Ship*>&) == &s ? " << (q == &s) << '\n';
}
