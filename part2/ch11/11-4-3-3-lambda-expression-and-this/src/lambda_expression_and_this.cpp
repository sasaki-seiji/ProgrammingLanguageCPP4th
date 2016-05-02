/*
 * lambda_expression_and_this.cpp
 *
 *  Created on: 2016/05/03
 *      Author: sasaki
 */

#include <functional>
#include <map>
#include <future>
#include <sstream>
#include <iostream>
using namespace std;

class Request {
	function<map<string,string>(const map<string,string>&)> oper;
	map<string,string> values;
	map<string,string> results;
public:
	Request(const string& s);

	future<void> execute()
	{
		return async([this](){ results = oper(values); });
	}

	map<string,string> get_values() const { return values; }
	map<string,string> get_results() const { return results; }
};

template<typename U, typename V>
ostream& operator<<(ostream& os, const map<U, V>& m)
{
	os << "[ ";
	for (const pair<U,V>& x : m)
		os << "(" << x.first << ", " << x.second << ") ";
	os << "]";
	return os;
}

int main()
{
	string str{"a 1 b 2 c 3 d 4 e 5"};
	Request req{str};
	future<void> fu = req.execute();
	fu.get();
	cout << req.get_values() << '\n';
	cout << req.get_results() << '\n';
}

// undefs

map<string,string> transform(const map<string,string>& m)
{
	map<string,string> res;
	for (const pair<string,string>& p : m)
		res[p.second] = p.first;
	return res;
}

Request::Request(const string& s) : oper{transform}
{
	istringstream is{s};
	string k, v;

	while (is) {
		is >> k;
		is >> v;
		values[k] = v;
	}
}
