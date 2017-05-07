/*
 * LSwidget.cpp
 *
 *  Created on: 2016/08/28
 *      Author: sasaki
 */

#include "LSwidget.h"


LSwidget::LSwidget(int l, int t, int w, int h, bool visible)
	: Window(l>=0?l:default_left, t>=0?t:default_top,
			w>=0?w:default_width, h>=0?h:default_height, visible)
{
}

