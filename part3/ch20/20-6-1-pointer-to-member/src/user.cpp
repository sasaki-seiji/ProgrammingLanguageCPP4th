/*
 * user.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Stdinterface.h"
#include "Window.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

void f(Std_interface* p)
{
	Pstd_mem s = &Std_interface::suspend;
	p->suspend();
	//p->*s();
		// error: must use '.*' or '->*' to call pointer-to-member function in 's (...)', e.g. '(... ->* s) (...)'
	(p->*s)();
}

map<string,Std_interface*> variable;
map<string,Pstd_mem> operation;

void call_member(string var, string oper)
{
#if 0
	cout << "var: " << var << ", address: " << variable[var] << flush << '\n';
	cout << "oper: " << oper << ", address: " << operation[oper] << flush << '\n';
#endif
	(variable[var]->*operation[oper])();
}

void interpreter()
{
	Window win1("w1"), win2("w2"), win3("w3");
	variable["win1"] = &win1;
	variable["win2"] = &win2;
	variable["win3"] = &win3;

	operation["start"] = &Std_interface::start;
	operation["suspend"] = &Std_interface::suspend;
	operation["resume"] = &Std_interface::resume;
	operation["quit"] = &Std_interface::quit;
	operation["full_size"] = &Std_interface::full_size;
	operation["small"] = &Std_interface::small;

	call_member("win1", "start");
	call_member("win2", "suspend");
	call_member("win3", "resume");
	call_member("win1", "quit");
	call_member("win2", "full_size");
	call_member("win3", "small");
}


class Task {
public:
	static void schedule();
};

void (*p)() = &Task::schedule;
//void (Task::*pm)() = &Task::schedule;
	// error: cannot convert 'void (*)()' to 'void (Task::*)()' in initialization


// add undef

void Task::schedule()
{
	cout << "Task::schedule()\n";
}

// add main

int main()
{
	Window win("w");
	f(&win);

	interpreter();

	(*p)();
}
