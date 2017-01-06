/*
 * My_messages.h
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */

#ifndef MY_MESSAGES_H_
#define MY_MESSAGES_H_

#include <vector>
#include <string>
#include <locale>
using std::vector;
using std::string;
using std::locale;
using std::messages;

struct Set {
	vector<string> msgs;
};

struct Cat {
	vector<Set> sets;
};

class My_messages : public messages<char> {
	vector<Cat>& catalogs;
public:
	explicit My_messages(size_t = 0) :catalogs{*new vector<Cat>} { }

	catalog do_open(const string& s, const locale& loc) const;

	string do_get(catalog cat, int s, int m, const string&) const;

	void do_close(catalog cat) const
	{
		if (cat<catalogs.size())
			catalogs.erase(catalogs.begin()+cat);
	}
};


#endif /* MY_MESSAGES_H_ */
