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
#include "My_messages.h"

enum Season { spring, summer, fall, winter };

extern std::string message_directory;

class Season_io : public std::locale::facet {
	const std::messages<char>& m;
	std::messages_base::catalog cat;
public:
	class Missing_messages { };

	Season_io(size_t i = 0)
		: std::locale::facet{i},
		  m(std::use_facet<My_messages>(std::locale())),
		  cat(m.open(message_directory,std::locale()))
		  {
			if (cat < 0)
				throw Missing_messages();
		  }

	~Season_io() { }

	// 2017.01.10 bug-fix : returns copy of string
	//const string& to_str(Season x) const;
	std::string to_str(Season x) const;
	bool from_str(const std::string& s, Season& x) const;

	static std::locale::id id;
};

std::ostream& operator<<(std::ostream& os, Season x);
std::istream& operator>>(std::istream& is, Season& x);

#endif /* SEASON_H_ */
