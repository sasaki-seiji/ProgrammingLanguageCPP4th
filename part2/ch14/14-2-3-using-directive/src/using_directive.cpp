/*
 * using_directive.cpp
 *
 *  Created on: 2016/05/23
 *      Author: sasaki
 */

#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<std::string> split(const string& s)
{
	vector<string> res;
	istringstream iss(s);
	for (string buf; iss >> buf; )
		res.push_back(buf);
	return res;
}

#include <iostream>
template<typename T>
ostream& operator<<(ostream&os, const vector<T>& v)
{
	cout << "[";
	for (auto& x : v)
		cout << x << ",";
	cout << "]";
	return os;
}
int main()
{
	vector<std::string> v = split("this is a pen");
	cout << v << '\n';
}

namespace Graph_lib {
	class Shape { };
	class Line : public Shape { };
	class Poly_line : public Shape { };
	class Text : public Shape { };

	Shape operator+(const Shape&, const Shape&);

	class Graph_reader { };
	Graph_reader open(const char*);
}

namespace Text_lib {
	class Glyph { };
	class Word { };
	class Line { };
	class Text { };

	class File { };
	File* open(const char*);

	Word operator+(const Line&, const Line&);
}

using namespace Graph_lib;
using namespace Text_lib;

Glyph gl;
vector<Shape*> vs;

//Text txt;
	// reference to 'Text' is ambiguous
//File* fp = open("my_precious_data");
	// call of overloaded 'open(const char [17])' is ambiguous

