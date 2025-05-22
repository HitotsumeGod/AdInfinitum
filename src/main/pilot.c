#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infinitum.h"

int main(void) {

	InfNode *i, *root;
	char *buf, *str;

	str = "wooah buddy!!";
	set_fs((root = init_inf(SIMPLE, NULL)));
	free(create_node_fsp("Unearthed"));
	move_fsp(1);
	free(create_node_fsp("Soulfire: Valor"));
	move_fsp(1);
	write_to_file(str, strlen(str) + 1, get_fsp());
	read_from_file(&buf, strlen(str) + 1, get_fsp());
	printf("%s\n", buf);
	free(buf);
	free_inf(root, NULL);
	return 0;

}
