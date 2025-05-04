#include <stdio.h>
#include "infinitum.h"

int main(void) {

	set_fs(init_inf(SIMPLE, NULL));
	create_node_fsp("goodfile");
	return 0;

}
