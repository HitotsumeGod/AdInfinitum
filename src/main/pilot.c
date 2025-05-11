#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infinitum.h"

int main(void) {

	InfNode *i, *root;

	set_fs((root = init_inf(SIMPLE, NULL)));
	free(create_node_fsp("Unearthed"));
	move_fsp(1);
	free(create_node_fsp("Soulfire: Valor"));
	move_fsp(1);
	write_to_file("wooah buddy!!", 12, get_fsp());
	free_inf(root, NULL);
	return 0;

}
