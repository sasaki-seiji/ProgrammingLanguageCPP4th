/*
 * smiley.cpp
 *
 *  Created on: 2016/03/26
 *      Author: sasaki
 */

#include <iostream>
using namespace std;

#include "smiley.h"

void Smiley::draw() const
{
	cout << "Smiley::draw() called\n";
	Circle::draw();
	for (auto p : eyes)
		p->draw();
	mouth->draw();
}

void Smiley::rotate(int angle)
{
	cout << "Smiley::rotate() called\n";
}
