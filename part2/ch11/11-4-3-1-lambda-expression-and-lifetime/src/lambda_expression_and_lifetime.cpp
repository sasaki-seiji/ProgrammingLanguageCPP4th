/*
 * lambda_expression_and_lifetime.cpp
 *
 *  Created on: 2016/05/02
 *      Author: sasaki
 */

#include <functional>
#include <iostream>
using namespace std;

struct Point {
	int x, y;
};
ostream& operator<<(ostream& os, Point pt)
{
	os << '(' << pt.x << ',' << pt.y << ')';
	return os;
}

class Menu {
private:
	function<void()> fn;
	string label;
public:
	void operator()() { fn(); }
	void add(const string& lb, function<void()> f) { fn = f; label = lb; }
	void draw(Point p1, Point p2, Point p3)
	{ cout << label << ": " << p1 << ',' << p2 << ',' << p3 << '\n'; }
};

void setup(Menu& m)
{
	Point p1{1,2}, p2{3,4}, p3{5,6};

	m.add("draw triagle", [&]{ m.draw(p1, p2, p3); });
}

void setup2(Menu& m)
{
	Point p1{1,2}, p2{3,4}, p3{5,6};

	//m.add("draw triagle", [=]{ m.draw(p1, p2, p3); });
	m.add("draw triagle", [=, &m]{ m.draw(p1, p2, p3); });
		// passing 'const Menu' as 'this' argument discards qualifiers [-fpermissive]
}

int main()
{
	Menu m;
	setup(m);
	m();

	setup2(m);
	m();
}


