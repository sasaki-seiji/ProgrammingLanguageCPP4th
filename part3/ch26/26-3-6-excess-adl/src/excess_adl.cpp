/*
 * excess_adl.cpp
 *
 *  Created on: 2016/09/24
 *      Author: sasaki
 */

// excess ADL

#include <vector>
#include <algorithm>
#include <iostream>

namespace User {
	class Customer
	{
		int id;
	public:
		Customer(int i) : id{i} { }
		int get_id() const { return id; }
	};
	using Index = std::vector<Customer*>;

	void copy(const Index& i1, Index& i2, int deep)
	{
		std::cout << "User::copy(const Index&, Index&, int)\n";
	}

	void algo(Index& x, Index& y)
	{
		std::cout << "-- User::algo(Index&,Index&) --\n";

		//copy(x,y,false);
			// error: no type named ‘value_type’ in ‘struct std::iterator_traits<std::vector<User::Customer*> >’
		User::copy(x,y,false);
	}
}

// add main


int main()
{
	User::Index c1 {new User::Customer(1), new User::Customer(2)};
	User::Index c2;
	User::algo(c1, c2);
}
