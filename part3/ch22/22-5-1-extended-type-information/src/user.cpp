/*
 * user.cpp
 *
 *  Created on: 2016/09/05
 *      Author: sasaki
 */

#include "Radio.h"
#include <typeinfo>
#include <typeindex>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct Layout {
	int size;
};

map<string, Layout> layout_table;

void f(Storable* p)
{
	Layout& x = layout_table[typeid(*p).name()];
	cout << typeid(*p).name() << ": " << x.size << '\n';
}

void layout_table_test()
{
	Component comp;
	Receiver rec;
	Transmitter trans;
	Radio radio;

	layout_table[typeid(comp).name()] = Layout{sizeof(comp)};
	layout_table[typeid(rec).name()] = Layout{sizeof(rec)};
	layout_table[typeid(trans).name()] = Layout{sizeof(trans)};
	layout_table[typeid(radio).name()] = Layout{sizeof(radio)};

	f(&comp);
	f(&rec);
	f(&trans);
	f(&radio);
}

struct Icon {
	string name;
};

unordered_map<type_index,Icon> icon_table;

void g(Storable* p)
{
	Icon& i = icon_table[type_index{typeid(*p)}];
	cout << type_index{typeid(*p)}.hash_code() << ": " << i.name << '\n';
}

void icon_table_test()
{
	Component comp;
	Receiver rec;
	Transmitter trans;
	Radio radio;

	icon_table[type_index{typeid(comp)}] = Icon{typeid(comp).name()};
	icon_table[type_index{typeid(rec)}] = Icon{typeid(rec).name()};
	icon_table[type_index{typeid(trans)}] = Icon{typeid(trans).name()};
	icon_table[type_index{typeid(radio)}] = Icon{typeid(radio).name()};

	g(&comp);
	g(&rec);
	g(&trans);
	g(&radio);
}


// add main

int main()
{
	layout_table_test();
	icon_table_test();
}
