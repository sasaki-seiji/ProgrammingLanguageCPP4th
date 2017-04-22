/*
 * base_member_and_derived_member.cpp
 *
 *  Created on: 2016/08/27
 *      Author: sasaki
 */

#include "Stdinterface.h"
#include <vector>
#include <iostream>
using namespace std;

class Text : public Std_interface {
public:
	void start();
	void suspend();
	void resume();
	void quit();
	void full_size();
	void small();

	virtual void print();
private:
	vector<int> s;
};

//void (Std_interface::*pmi)() = &Text::print;
	// error: cannot convert 'void (Text::*)()' to 'void (Std_interface::*)()' in initialization
void (Text::*pmt)() = &Std_interface::start;


// add main

int main()
{
	Text text;
	(text.*pmt)();
}

// add undefs

void Text::start()
{
	cout << "Text::start()\n";
}
void Text::suspend()
{
	cout << "Text::suspend()\n";
}
void Text::resume()
{
	cout << "Text::resume()\n";
}
void Text::quit()
{
	cout << "Text::quit()\n";
}
void Text::full_size()
{
	cout << "Text::full_size()\n";
}
void Text::small()
{
	cout << "Text::small()\n";
}

void Text::print()
{
	cout << "Text::print()\n";
}



