/*
 * hasher_and_equality.cpp
 *
 *  Created on: 2016/11/27
 *      Author: sasaki
 */


#include <unordered_set>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

struct Record {
	string name;
	int val;
};

struct Nocase_hash {
	int d = 1;
	size_t operator()(const Record& r) const
	{
		size_t h = 0;
		for (auto x : r.name) {
			h <<= d;
			h ^= toupper(x);
		}
		return h;
	}
	// 2016.11.27 add
	Nocase_hash(int dd=1) : d{dd} { }
	//error: no matching function for call to 'Nocase_hash::Nocase_hash(<brace-enclosed initializer list>)'
	//   Nocase_hash{2},
};

struct Nocase_equal {
	bool operator()(const Record& r, const Record& r2) const
	{
		if (r.name.size()!=r2.name.size()) return false;
		for (size_t i = 0; i<r.name.size(); ++i)
			if (toupper(r.name[i])!=toupper(r2.name[i]))
				return false;
		return true;
	}
};

void specify_hash_and_equal_function()
{
	cout << "--- specify_hash_and_equal_function() ---\n";

	unordered_set<Record,Nocase_hash,Nocase_equal> m {
		{ {"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12} },
		20,
		Nocase_hash{2},
		Nocase_equal{}
	};

	cout << "size: " << m.size() << endl;
	cout << "bucket_count: " << m.bucket_count() << endl;

	for (auto r : m)
		cout << "{" << r.name << ',' << r.val << "}\n";
}

void default_hash_and_equal_function()
{
	cout << "--- deault_hash_and_equal_function() ---\n";

	unordered_set<Record,Nocase_hash,Nocase_equal> m {
		{ {"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12} }
	};

	cout << "size: " << m.size() << endl;
	cout << "bucket_count: " << m.bucket_count() << endl;

	for (auto r : m)
		cout << "{" << r.name << ',' << r.val << "}\n";
}

size_t hf(const Record& r)
	{ return hash<string>()(r.name)^hash<int>()(r.val); }
bool eq(const Record& r, const Record& r2)
	{ return r.name==r2.name && r.val==r2.val; }

void specialized_standand_hash_and_equal()
{
	cout << "--- specialized_standand_hash_and_equal() ---\n";

	unordered_set<Record, decltype(&hf),decltype(&eq)> m {
		{ {"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12} },
		20,
		hf,
		eq
	};

	cout << "size: " << m.size() << endl;
	cout << "bucket_count: " << m.bucket_count() << endl;

	for (auto r : m)
		cout << "{" << r.name << ',' << r.val << "}\n";

	unordered_set<Record, decltype(&hf),decltype(&eq)> m2 {10,hf,eq};

	cout << "size: " << m2.size() << endl;
	cout << "bucket_count: " << m2.bucket_count() << endl;
}

void lambda_hash_and_equal_function()
{
	cout << "--- lambda_hash_and_equal_function() ---\n";

	unordered_set<
		Record,
		function<size_t(const Record&)>,
		function<bool(const Record&, const Record&)>
	> m {
		{ {"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12} },
		10,
		[](const Record& r)
				{ return hash<string>{}(r.name)^hash<int>{}(r.val); },
		[](const Record& r, const Record& r2)
				{ return r.name==r2.name && r.val==r2.val; }
	};

	cout << "size: " << m.size() << endl;
	cout << "bucket_count: " << m.bucket_count() << endl;

	for (auto r : m)
		cout << "{" << r.name << ',' << r.val << "}\n";
}

void named_hash_and_equal_lambda_function()
{
	cout << "--- named_hash_and_equal_lambda_function() ---\n";

	auto hf = [](const Record& r)
					{ return hash<string>{}(r.name)^hash<int>{}(r.val); };
	auto eq = [](const Record& r, const Record& r2)
					{ return r.name==r2.name && r.val==r2.val; };

	unordered_set<Record,decltype(hf),decltype(eq)> m {
		{ {"andy",7}, {"al",9}, {"bill",-3}, {"barbara",12} },
		10, hf, eq};

	cout << "size: " << m.size() << endl;
	cout << "bucket_count: " << m.bucket_count() << endl;

	for (auto r : m)
		cout << "{" << r.name << ',' << r.val << "}\n";
}

namespace std {

	template<>
	struct hash<Record> {
		size_t operator()(const Record& r) const
		{
			return hash<string>{}(r.name)^hash<int>{}(r.val);
		}
	};

	template<>
	struct equal_to<Record> {
		bool operator()(const Record& r, const Record& r2) const
		{
			return r.name==r2.name && r.val==r2.val;
		}
	};
}

void specialize_hash_and_equal_to_template()
{
	cout << "--- specialize_hash_and_equal_to_template() ---\n";

	unordered_set<Record> m1;
	unordered_set<Record> m2;

	cout << "size: " << m1.size() << endl;
	cout << "bucket_count: " << m1.bucket_count() << endl;
}


int main()
{
	specify_hash_and_equal_function();
	default_hash_and_equal_function();
	specialized_standand_hash_and_equal();
	lambda_hash_and_equal_function();
	named_hash_and_equal_lambda_function();
	specialize_hash_and_equal_to_template();
}

