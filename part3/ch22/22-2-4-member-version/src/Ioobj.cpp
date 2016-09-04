/*
 * Ioobj.cpp
 *
 *  Created on: 2016/09/04
 *      Author: sasaki
 */

#include "Ioobj.h"

map<string, Pf> io_map;

string get_word(istream& is)
{
	string str;
	is >> str;
	return str;
}

Io_obj* get_obj(istream& is)
{
	string str = get_word(is);
	if (auto f = io_map[str])
		return f(is);
	throw Unknown_class{};
}
