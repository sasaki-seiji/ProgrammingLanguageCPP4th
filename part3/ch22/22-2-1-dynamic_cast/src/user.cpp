/*
 * user.cpp
 *
 *  Created on: 2016/09/03
 *      Author: sasaki
 */


#include "BBivalslider.h"
#include "Myslider.h"
#include "Date.h"
#include "Ioobj.h"
#include <iostream>
using namespace std;

void f(BB_ival_slider* p)
{
	cout << "-- f(BB_ival_slider*) --\n";
	p->display_info();

	Ival_slider* pi1 = p;
	Ival_slider* pi2 = dynamic_cast<Ival_slider*>(p);
	cout << "p(BB_ival_slider*): " << p << '\n';
	cout << "pi1(Ival_slider* pi1 = p): " << pi1 << '\n';
	cout << "pi2(dynamic_cast<Ival_slider*>(p)): " << pi2 << '\n';

	//BBslider* pbb1 = p;
		// error: 'BBslider' is an inaccessible base of 'BB_ival_slider'
	//BBslider* pbb2 = dynamic_cast<BBslider*>(p);
		// error: 'BBslider' is an inaccessible base of 'BB_ival_slider'
}

void g(Ival_box* pb, Date* pd)
{
	cout << "-- g(Ival_box*, Date*) --\n";

	My_slider* pb1 = dynamic_cast<My_slider*>(pb);
	//My_date* pd1 = dynamic_cast<My_date*>(pd);
		// error: cannot dynamic_cast 'pd' (of type 'struct Date*') to type 'class My_date*' (source type is not polymorphic)

	void* pb2 = dynamic_cast<void*>(pb);
	//void* pd2 = dynamic_cast<void*>(pd);
		// error: cannot dynamic_cast 'pd' (of type 'struct Date*') to type 'void*' (source type is not polymorphic)

	cout << "pb(Ival_box*): " << pb << '\n';
	cout << "pb1(dynamic_cast<My_slider*>(pb)): " << pb1 << '\n';
	cout << "pb1(dynamic_cast<void*>(pb): " << pb2 << '\n';
}

void f(Io_obj* pio)
{
	cout << "-- f(Io_obj*) --\n";

	Date* pd = dynamic_cast<Date*>(pio);

	cout << "pio(Io_obj*): " << pio << '\n';
	cout << "pd(dynamic_cast<Date*>(pio)): " << pd << '\n';
}

// add main

int main()
{
	BB_ival_slider slider{0,99};
	f(&slider);

	My_slider myslider;
	My_date mydate{2016,9,3};
	g(&myslider, &mydate);

	Date d{2016,9,3};
	Io_date io_date{d};

	f(&io_date);
}
