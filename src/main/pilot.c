#include <stdio.h>
#include <stdlib.h>
#include "infinitum.h"

int main(void) {

	InfNode *i;

	init_inf(SIMPLE, NULL);
	for (FSP = FSR; (i = get_fsp()) != NULL; move_fsp_f(1)) 
		printf("%s\n", i -> filename);
	free_inf(FSR);
	return 0;

}
