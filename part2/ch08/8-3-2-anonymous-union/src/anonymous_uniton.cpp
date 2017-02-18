/*
 * anonymous_niton.cpp
 *
 *  Created on: 2016/04/22
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

class Entry2 {
private:
	enum class Tag { number, text };
	Tag type;
	union {
		int i;
		string s;
	};
public:
	struct Bad_entry { };

	string name;

	~Entry2();
	Entry2& operator=(const Entry2&);
	Entry2(const Entry2&);
	Entry2(int ii=0);
	Entry2(const string& ss);

	int number() const;
	string text() const;

	void set_number(int n);
	void set_text(const string&);
};

Entry2::Entry2(int ii) :type{Tag::number}, i{ii}
{
}

Entry2::Entry2(const string& ss) :type{Tag::text}, s{ss}
{
}

Entry2::~Entry2()
{
	if (type == Tag::text) s.~string();
}

int Entry2::number() const
{
	if (type != Tag::number) throw Bad_entry();
	return i;
}

string Entry2::text() const
{
	if (type != Tag::text) throw Bad_entry();
	return s;
}

void Entry2::set_number(int n)
{
	if (type == Tag::text){
		s.~string();
		type = Tag::number;
	}
	i = n;
}

void Entry2::set_text(const string& ss)
{
	if (type == Tag::text)
		s = ss;
	else {
		new(&s) string{ss};
		type = Tag::text;
	}
}

Entry2& Entry2::operator=(const Entry2& e)
{
	if (type == Tag::text && e.type == Tag::text) {
		s = e.s;
		return *this;
	}

	if (type == Tag::text) s.~string();

	switch (e.type) {
	case Tag::number:
		i = e.i;
		// 2016.04.22 add
		type = e.type;
		break;
	case Tag::text:
		// 2016.04.22 change: syntax error
		// new(&s)(e.s);
		new(&s) string{e.s};
		type = e.type;
		break;
	}

	return *this;
}

int main()
{
	Entry2 e{123};
	cout << "e.number() = " << e.number() << '\n';

	e.set_text("a string");
	cout << "after e.set_text(\"a string\"), e.text() = " << e.text() << '\n';

	e.set_number(111);
	cout << "after e.set_number(111), e.nubmer() = " << e.number() << '\n';

	// number = number
	{
		Entry2 t{10};
		Entry2 s{20};
		t = s;
		cout << "after t(10) = s(20), t.number() = " << t.number() << '\n';
	}

	// number = string
	{
		Entry2 t{11};
		Entry2 s{"source"};
		t = s;
		cout << "after t(11) = s(\"source\"), t.text() = " << t.text() << '\n';
	}

	// string = number
	{
		Entry2 t{"target"};
		Entry2 s{21};
		t = s;
		cout << "after t(\"target\") = s(21), t.number() = " << t.number() << '\n';
	}

	// string = string
	{
		Entry2 t{"target"};
		Entry2 s{"source"};
		t = s;
		cout << "after t(\"target\") = s(\"source\"), t.text() = " << t.text() << '\n';
	}

	return 0;
}

