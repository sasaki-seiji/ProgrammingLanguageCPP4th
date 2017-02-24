/*
 * calculator_lowinput.cpp
 *
 *  Created on: 2016/04/25
 *      Author: sasaki
 */

#include <iostream>
#include <map>
#include <cctype>
using namespace std;

int no_of_errors;

void error(const string& s)
{
	no_of_errors++;
	cerr << "error: " << s << '\n';
	exit(1);
}

enum class Kind : char {
	name, number, end,
	plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
};

struct Token {
	Kind kind;
	string string_value;
	double number_value;
};

struct Enode {
	Token token;
	Enode* left;
	Enode* right;
};

class Token_stream {
public:
	Token_stream(istream& s) : ip{&s}, owns{false} { }
	Token_stream(istream* p) : ip{p}, owns{true} { }

	~Token_stream() { close(); }

	Token get();
	const Token& current() { return ct; }

	void set_input(istream& s) { close(); ip = &s; owns = false; }
	void set_input(istream* p) { close(); ip = p; owns = true; }

private:
	void close() { if (owns) delete ip; }

	istream* ip;
	bool owns;
	Token ct {Kind::end};
};

Token Token_stream::get()
{
	char ch;

	do {
		if (!ip->get(ch)) return ct={Kind::end};
	} while (ch != '\n' && isspace(ch));

	switch (ch){
	case ';':
	case '\n':
		return ct={Kind::print};
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return ct={static_cast<Kind>(ch)};
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		ip->putback(ch);
		*ip >> ct.number_value;
		ct.kind = Kind::number;
		return ct;
	default:
		if (isalpha(ch)){
			ct.string_value = ch;
			while (ip->get(ch))
				if (isalnum(ch))
					ct.string_value += ch;
				else {
					ip->putback(ch);
					break;
				}
			ct.kind = Kind::name;
			return ct;
		}

		error("bad token");
		return ct={Kind::print};
	}
}

extern Token_stream ts;
map<string, double> table;

Enode* prim(bool get);
Enode* term(bool get);
Enode* expr(bool get);

Enode* expr(bool get)
{
	Enode* left = term(get);

	for (;;) {
		switch (ts.current().kind) {
		case Kind::plus:
		case Kind::minus:
		{
			Token t = ts.current();
			left = new Enode {t, left, term(true)};
			break;
		}
		default:
			return left;
		}
	}
}

Enode* term(bool get)
{
	Enode* left = prim(get);

	for (;;){
		switch (ts.current().kind){
		case Kind::mul:
		case Kind::div:
		{
			Token t = ts.current();
			left = new Enode {t, left, prim(true)};
			break;
		}
		default:
			return left;
		}
	}
}

Enode* prim(bool get)
{
	if (get) ts.get();

	switch (ts.current().kind){
	case Kind::number:
	{
		Enode* v = new Enode {ts.current(), nullptr, nullptr};
		ts.get();
		return v;
	}
	case Kind::name:
	{
		Enode *v = new Enode {ts.current(), nullptr, nullptr};
		if (ts.get().kind == Kind::assign) {
			Token t = ts.current();
			v = new Enode {t, v, expr(true)};
		}
		return v;
	}
	case Kind::minus:
	{
		Token t = ts.current();
		return new Enode {t, prim(true), nullptr};
	}
	case Kind::lp:
	{
		auto e = expr(true);
		if (ts.current().kind != Kind::rp) error("')' expected");
		ts.get();
		return e;
	}
	default:
		error("primary expected");
	}
}

void generate(Enode* n)
{
	cout << "-- generate(" << static_cast<int>(n->token.kind) << ") --\n";

	switch (n->token.kind) {
	case Kind::number:
		cout << " pushi " << n->token.number_value << endl;
		break;
	case Kind::name:
		cout << " load " << n->token.string_value << endl;
		break;
	case Kind::assign:
		generate(n->right);
		cout << " dup" << endl;
		cout << " store " << n->left->token.string_value << endl;
		break;
	case Kind::plus:
		generate(n->left);
		generate(n->right);
		cout << " add" << endl;
		break;
	case Kind::minus:
		if (n->right) {
			generate(n->left);
			generate(n->right);
			cout << " sub" << endl;
		}
		else {
			generate(n->left);
			cout << " neg" << endl;
		}
		break;
	case Kind::mul:
		generate(n->left);
		generate(n->right);
		cout << " mul" << endl;
		break;
	case Kind::div:
		generate(n->left);
		generate(n->right);
		cout << " div" << endl;
		break;
	case Kind::end:  case Kind::print:  case Kind::lp:  case Kind::rp:
		break;
	}
}

Token_stream ts{cin};

void calculate()
{
	Enode *n;
	for (;;){
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		n = expr(false);
		generate(n);
		cout << " print" << endl;
	}
}

int main()
{
	table["pi"] = 3.14159;
	table["e"] = 2.71828;

	calculate();

	return no_of_errors;
}



