#include <stdlib.h>
#include <errno.h>
#include "infinitum.h"

void move_fsp_f(long long places) {

	for (long long ll = 0; ll < places; ll++)
		if (!FSP)
			return;
		else
			FSP = FSP -> next;

}

void move_fsp_b(long long places) {

	for (long long ll = 0; ll < places; ll++)
		if (!FSP)
			return;
		else
			FSP = FSP -> prev;

}

InfNData *query_fsp(void) {

	InfNData *ndata;

	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;
		return NULL;
	}
	ndata -> fd = FSP -> fd;
	ndata -> filename = FSP -> filename;
	ndata -> is_grouper = FSP -> is_grouper;
	ndata -> is_root = FSP -> is_root;
	return ndata;

}

InfNode *get_fsp(void) { return FSP; }

InfNData *create_node_fsp(char *filename) {

	InfNode *fsn;
	InfNData *ndata;

	if (FSP -> next) {
		errno = NODE_CREATION_ERR;
		return NULL;
	}
	if ((fsn = malloc(sizeof(InfNode))) == NULL || (ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;
		return NULL;
	}
	fsn -> fd = FSP -> fd + 1;
	fsn -> filename = filename;
	fsn -> is_grouper = false;
	fsn -> is_root = false;
	fsn -> data = NULL;
	fsn -> prev = FSP;
	fsn -> next = NULL;
	FSP -> next = fsn;
	ndata -> fd = fsn -> fd;
	ndata -> filename = fsn -> filename;
	ndata -> is_grouper = fsn -> is_grouper;
	ndata -> is_root = fsn -> is_root;
	return ndata;

}
