/*
 * c_part.c
 *
 *  Created on: 2016/05/14
 *      Author: sasaki
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void c_function(void)
{
	printf("-- c_function() --\n");
	errno = E_CPLPLFCTBLEWIT;
}

void c_entry(void)
{
	printf("-- c_entry() --\n");
	errno = 0 ;
	call_from_C();
	if (errno) {
		printf("error occurs, errno: %d\n", errno);
	}
}
