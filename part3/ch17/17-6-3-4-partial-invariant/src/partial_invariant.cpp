/*
 * partial_invariant.cpp
 *
 *  Created on: 2016/08/05
 *      Author: sasaki
 */

#include <vector>
using namespace std;

class Tic_tac_toe {
public:
	Tic_tac_toe(): pos(9) {}

	Tic_tac_toe& operator=(const Tic_tac_toe& arg)
	{
		for (int i = 0; i<9; ++i)
			pos.at(i) = arg.pos.at(i);
		return *this;
	}

	enum State { empty, nought, cross };
private:
	vector<State> pos;
};

class Tic_tac_toe2 {
public:
	Tic_tac_toe2(): pos(9) {}
	Tic_tac_toe2(const Tic_tac_toe2&) = default;
	Tic_tac_toe2& operator=(const Tic_tac_toe2&) = default;
	~Tic_tac_toe2() = default;

	enum State { empty, nought, cross };
private:
	vector<State> pos;
};

class Tic_tac_toe3 {
public:
	enum State { empty, nought, cross };
private:
	vector<State> pos {vector<State>(9)};
};

// add main

int main()
{
	Tic_tac_toe toe11, toe12; // no destructor
	toe11 = toe12;
	Tic_tac_toe toe13{toe11};	// not defined copy-constructor

	Tic_tac_toe2 toe21, toe22;
	toe21 = toe22;
	Tic_tac_toe2 toe23{toe21};

	Tic_tac_toe3 toe31, toe32;
	toe31 = toe32;
	Tic_tac_toe3 toe33{toe31};
}
