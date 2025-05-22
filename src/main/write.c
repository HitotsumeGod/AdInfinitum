#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "infinitum.h"

size_t write_to_file(char *buf, size_t sz, InfNode *f) {

	int i;

	if (!buf || !f) {
		errno = BAD_ARGS_ERR;
		return -1;
	}
	if ((f -> data = malloc(sizeof(char) * sz)) == NULL) {
		errno = MALLOC_ERR;
		return -1;
	}
	for (i = 0; i < sz; i++) 
		*(f -> data + i) = *(buf + i);
	f -> is_modified = true;
	return i;

}

size_t read_from_file(char **buf, size_t sz, InfNode *f) {

	char *str;
	int i;

	if (sz < 1 || !f) {			
		errno = BAD_ARGS_ERR;
		return -1;
	}
	if ((str = malloc(sizeof(char) * sz)) == NULL) {
		errno = MALLOC_ERR;
		return -1;
	}
	for (int i = 0; i < sz; i++)
		*(str + i) = *(f -> data + i);
	*buf = str;
	f -> is_modified = true;
	return i;

}
