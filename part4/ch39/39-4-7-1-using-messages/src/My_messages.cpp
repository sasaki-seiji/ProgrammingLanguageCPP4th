/*
 * My_messages.cpp
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */

#include <fstream>
#include "My_messages.h"
using namespace std;

string
My_messages::do_get(catalog cat, int set, int id, const string& def) const
{
	if (catalogs.size()<=cat)
		return def;
	Cat& c = catalogs[cat];
	if (c.sets.size()<=set)
		return def;
	Set& s = c.sets[set];
	if (s.msgs.size()<=id)
		return def;
	return s.msgs[id];
}

messages<char>::catalog
My_messages::do_open(const string& n, const locale& loc) const
{
	string name = loc.name();
	if (name=="*") name = "unknown";
	string nn = n + name;
	ifstream f(nn.c_str());
	if (!f) return -1;

	catalogs.push_back(Cat{});
	Cat& c = catalogs.back();

	//for(string s; f>>s && s=="<<<"; ) {
	for(string s; getline(f,s) && s=="<<<"; ) {
		c.sets.push_back(Set{});
		Set& ss = c.sets.back();
		while (getline(f,s) && s != ">>>")
			ss.msgs.push_back(s);
	}
	return catalogs.size()-1;
}



