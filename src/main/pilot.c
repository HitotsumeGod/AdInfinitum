#include <stdio.h>
#include <stdlib.h>
#include "infinitum.h"

int main(void) {

	InfNode *i;

	set_fs(init_inf(SIMPLE, NULL));
	create_node_fsp("goodfile");
	move_fsp_f(1);
	create_node_fsp("hasangang");
	for (move_fsp_b(1); (i = get_fsp()) != NULL; move_fsp_f(1)) 
		printf("%s\n", i -> filename);
	return 0;

}
