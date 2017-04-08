/*
 * partial_invariant.cpp
 *
 *  Created on: 2016/08/05
 *      Author: sasaki
 */

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	for (auto x : v)
		os << x << ", ";
	return os;
}

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
	enum State& operator[](int i) { return pos[i]; }
private:
	vector<State> pos;

	friend ostream& operator<<(ostream& os,const Tic_tac_toe& toe)
	{ return os << toe.pos; }
};

class Tic_tac_toe2 {
public:
	Tic_tac_toe2(): pos(9) {}
	Tic_tac_toe2(const Tic_tac_toe2&) = default;
	Tic_tac_toe2& operator=(const Tic_tac_toe2&) = default;
	~Tic_tac_toe2() = default;

	enum State { empty, nought, cross };
	enum State& operator[](int i) { return pos[i]; }
private:
	vector<State> pos;

	friend ostream& operator<<(ostream& os,const Tic_tac_toe2& toe)
	{ return os << toe.pos; }
};

class Tic_tac_toe3 {
public:
	enum State { empty, nought, cross };
	enum State& operator[](int i) { return pos[i]; }
private:
	vector<State> pos {vector<State>(9)};
	friend ostream& operator<<(ostream& os,const Tic_tac_toe3& toe)
	{ return os << toe.pos; }
};

// add main

int main()
{
	Tic_tac_toe toe11, toe12; // no destructor
	toe12[7] = Tic_tac_toe::State::cross;
	cout << "toe11: " << toe11 << ", toe12: " << toe12 << endl;

	toe11 = toe12;
	cout << "toe11 = toe12;　toe11: " << toe11 << endl;

	Tic_tac_toe toe13{toe11};	// not defined copy-constructor
	cout << "Tic_tac_toe toe13{toe11}; toe13: " << toe13 << endl;

	Tic_tac_toe2 toe21, toe22;
	toe22[5] = Tic_tac_toe2::State::nought;
	cout << "toe21: " << toe21 << ", toe22: " << toe22 << endl;

	toe21 = toe22;
	cout << "toe21 = toe22;　toe21: " << toe21 << endl;

	Tic_tac_toe2 toe23{toe21};
	cout << "Tic_tac_toe2 toe23{toe21}; toe23: " << toe23 << endl;

	Tic_tac_toe3 toe31, toe32;
	toe32[3] = Tic_tac_toe3::State::cross;
	cout << "toe31: " << toe31 << ", toe32: " << toe32 << endl;

	toe31 = toe32;
	cout << "toe31 = toe32;　toe31: " << toe31 << endl;

	Tic_tac_toe3 toe33{toe31};
	cout << "Tic_tac_toe3 toe33{toe31}; toe33: " << toe33 << endl;
}
