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

struct Set {
	std::vector<std::string> msgs;
};

struct Cat {
	std::vector<Set> sets;
};

class My_messages : public std::messages<char> {
	std::vector<Cat>& catalogs;
public:
	explicit My_messages(size_t = 0) :catalogs{*new std::vector<Cat>} { }

	catalog do_open(const std::string& s, const std::locale& loc) const;

	std::string do_get(catalog cat, int s, int m, const std::string&) const;

	void do_close(catalog cat) const
	{
		if (cat<catalogs.size())
			catalogs.erase(catalogs.begin()+cat);
	}
};


#endif /* MY_MESSAGES_H_ */
