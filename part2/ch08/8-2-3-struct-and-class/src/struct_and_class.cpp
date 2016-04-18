/*
 * struct_and_class.cpp
 *
 *  Created on: 2016/04/18
 *      Author: sasaki
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::ostream;
using std::cout;
using std::cerr;
using std::ostringstream;
using std::vector;
using std::string;

struct Point {
	int x, y;
};

ostream& operator<<(ostream& os, const Point& pt)
{
	os << "( " << pt.x << ", " << pt.y << " )";
	return os;
}

struct Points {
	vector<Point> elem;
	Points(Point p0) { elem.push_back(p0); }
	Points(Point p0, Point p1) { elem.push_back(p0); elem.push_back(p1); }
};

//Points x0;
	// no matching function for call to 'Points::Points()'
Points x1{ {100,200} };
Points x2{ {100,200}, {300,400} };

struct Address {
	string name;
	int number;
	string street;
	string town;
	char state[2];
	char zip[5];

	Address(const string& n, int nu, const string& s, const string& t,
			const string& st, int z);
};

ostream& operator<<(ostream& os, const Address ad)
{
	os << ad.name << '\n'
			<< ad.number << ' ' << ad.street << '\n'
			<< ad.town << '\n'
			<< ad.state[0] << ad.state[1] << ' ' ;
	for (size_t i = 0; i < sizeof(ad.zip); ++i)
		os << ad.zip[i];
	os << '\n';

	return os;
}

void error(const char* message)
{
	cerr << message << '\n';
}

Address::Address(const string& n, int nu, const string& s, const string&t,
		const string& st, int z)
	:name{n},
	 number{nu},
	 street{s},
	 town{t},
	 state{st[0],st[1]}	// 2016.04.18 move from body
{
	if (st.size()!=2)
		error("State abbreviation should be two characters");
	//state = {st[0], st[1]};
	ostringstream ost;
	ost << z;
	string zi {ost.str()};
	switch (zi.size()) {
	case 5:
		//zip = {zi[0], zi[1], zi[2], zi[3], zi[4]};
		for (int i = 0; i < 5; ++i) zip[i] = zi[i];
		break;
	case 4:
		//zip = {'0', zi[0], zi[1], zi[2], zi[3]};
		zip[0] = '0';
		for (int i = 0; i < 4; ++i) zip[i+1] = zi[i];
		break;
	default:
		error("unexpected ZIP code format");
	}
}

Address jd = {
	"Jim Dandy",
	61, "South St",
	"New Providence",
	"NJ", 7974
};

int main()
{
	Point p0;
	Point p1 {};
	Point p2 {1};
	Point p3 {1,2};

	cout << "p0 = " << p0 << '\n';
	cout << "p1 = " << p1 << '\n';
	cout << "p2 = " << p2 << '\n';
	cout << "p3 = " << p3 << '\n';

	cout << jd;
}

