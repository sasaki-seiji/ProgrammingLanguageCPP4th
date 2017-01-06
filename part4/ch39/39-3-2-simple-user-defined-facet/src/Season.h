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

enum Season { spring, summer, fall, winter };

class Season_io : public locale::facet {
public:
	//Season_io(int i = 0) : locale::facet{i} { }
	Season_io(size_t i = 0) : locale::facet{i} { }
	~Season_io() { }

	virtual const string& to_str(Season x) const = 0;
	virtual bool from_str(const string& s, Season& x) const = 0;

	static locale::id id;
};

ostream& operator<<(ostream& os, Season x);
istream& operator>>(istream& is, Season& x);

class US_season_io : public Season_io {
	static const string seasons[];
public:
	const string& to_str(Season) const override;
	bool from_str(const string&, Season&) const override;
};

#endif /* SEASON_H_ */
