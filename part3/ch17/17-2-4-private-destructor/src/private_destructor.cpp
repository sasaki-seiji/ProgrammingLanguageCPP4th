/*
 * private_destructor.cpp
 *
 *  Created on: 2016/07/24
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class Nonlocal {
public:
	Nonlocal();
	void destroy() { delete this; }
private:
	~Nonlocal();
};

void user()
{
	//Nonlocal x;
		// error: 'Nonlocal::~Nonlocal()' is private
	Nonlocal* p = new Nonlocal;

	//delete p;
		// error: 'Nonlocal::~Nonlocal()' is private
	p->destroy();
}

// add undef-func
Nonlocal::Nonlocal()
{
	cout << "Nonlocal()\n";
}
Nonlocal::~Nonlocal()
{
	cout << "~Nonlocal()\n";
}

// add main
int main()
{
	user();
}
