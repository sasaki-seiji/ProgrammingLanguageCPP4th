/*
 * c_part.c
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void c_function(void)
{
	printf("c_function() called\n");
	errno = E_CPLPLFCTBLEWIT;
}

void c_entry(void)
{
	printf("c_entry() called\n");
	errno = 0 ;
	call_from_C();
	if (errno) {
		printf("error occurs, errno: %d\n", errno);
	}
}
