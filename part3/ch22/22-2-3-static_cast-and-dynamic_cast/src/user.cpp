/*
 * user.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */


#include "Radio.h"
#include "Users.h"
#include <iostream>
using namespace std;

void g(Radio& r)
{
	cout << "Radio* &r: " << &r << '\n';

	Receiver* prec = &r;
	cout << "Receiver* prec = &r: " << prec << '\n';

	Radio* pr = static_cast<Radio*>(prec);
	cout << "Radio* pr = static_cast<Radio*>(prec): " << pr << '\n';

	pr = dynamic_cast<Radio*>(prec);
	cout << "pr = dynamic_cast<Radio*>(prec): " << pr << '\n';

	Storable *ps = &r;
	cout << "Storable *ps = &r: " << ps << '\n';

	//pr = static_cast<Radio*>(ps);
		// error: cannot convert from pointer to base class 'Storable' to pointer to derived class 'Radio' because the base is virtual

	pr = dynamic_cast<Radio*>(ps);
	cout << "pr = dynamic_cast<Radio*>(ps): " << pr << '\n';
}

Radio* f1(void* p)
{
	Storable* ps = static_cast<Storable*>(p);
	return dynamic_cast<Radio*>(ps);
}

void f2(Users* pu, const Receiver* pcr)
{
	//static_cast<set<Person>*>(pu);
		// error: 'std::set<Person>' is an inaccessible base of 'Users'
	//dynamic_cast<set<Person>*>(pu);
		//  error: 'std::set<Person>' is an inaccessible base of 'Users'
	//static_cast<Receiver*>(pcr);
		// error: static_cast from type 'const Receiver*' to type 'Receiver*' casts away qualifiers
	//dynamic_cast<Receiver*>(pcr);
		// error: cannot dynamic_cast 'pcr' (of type 'const class Receiver*') to type 'class Receiver*' (conversion casts away constness)

	Receiver* pr = const_cast<Receiver*>(pcr);
	pr->dummy = 1000;
}

// add main

int main()
{
	Radio r;
	g(r);

	Storable *ps = &r;
	Radio* pr = f1(ps);
	cout << "Radio* pr; pr->dummy: " << pr->dummy << '\n';

	Users users;
	Receiver rec;
	f2(&users, &rec);
	cout << "rec.dummy: " << rec.dummy << '\n';
}
