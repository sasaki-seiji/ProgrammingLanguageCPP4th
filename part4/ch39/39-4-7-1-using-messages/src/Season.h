/*
 * Season.h
 *
 *  Created on: 2017/01/06
 *      Author: sasaki
 */

#ifndef SEASON_H_
#define SEASON_H_

#include <locale>
#include <string>
#include <iostream>
using std::locale;
using std::string;
using std::istream;
using std::ostream;
using std::messages;
using std::messages_base;
using std::use_facet;
#include "My_messages.h"

enum Season { spring, summer, fall, winter };

extern string message_directory;

class Season_io : public locale::facet {
	const messages<char>& m;
	messages_base::catalog cat;
public:
	class Missing_messages { };

	Season_io(size_t i = 0)
		: locale::facet{i},
		  m(use_facet<My_messages>(locale())),
		  cat(m.open(message_directory,locale()))
		  {
			if (cat < 0)
				throw Missing_messages();
		  }

	~Season_io() { }

	// 2017.01.10 bug-fix : returns copy of string
	//const string& to_str(Season x) const;
	string to_str(Season x) const;
	bool from_str(const string& s, Season& x) const;

	static locale::id id;
};

ostream& operator<<(ostream& os, Season x);
istream& operator>>(istream& is, Season& x);

#endif /* SEASON_H_ */
