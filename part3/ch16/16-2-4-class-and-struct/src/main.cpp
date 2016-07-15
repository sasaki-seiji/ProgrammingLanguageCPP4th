/*
 * main.cpp
 *
 *  Created on: 2016/07/16
 *      Author: sasaki
 */

#include "Date1.h"
#include "Date2.h"
#include "Date3.h"
#include "Date4.h"

int main()
{
	Date1 d1 {16, 7, 2016};
	Date2 d2 {1, 1, 1970};
	Date3 d3 {30, 12, 1950};
	Date4 d4 {25, 12, 1959};

	d1.print();
	d2.print();
	d3.print();
	d4.print();
}

