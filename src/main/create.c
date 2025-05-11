#include <stdlib.h>
#include <errno.h>
#include "infinitum.h"

InfNData *create_node(char *fname) {

	InfNode *cnode, *newnode;
	InfNData *ndata;

	if (!fname) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	cnode = FSR;
	while (cnode -> next)
		cnode = cnode -> next;
	if ((newnode = malloc(sizeof(InfNode))) == NULL || (ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;
		return NULL;
	}
	newnode -> fd = ndata -> fd = cnode -> fd + 1;
	newnode -> filename = ndata -> filename = fname;
	newnode -> is_grouper = ndata -> is_grouper = false;
	newnode -> is_in_group = ndata -> is_in_group = false;
	newnode -> is_root = ndata -> is_root = false;
	newnode -> is_modified = false;
	newnode -> data = NULL;
	newnode -> prev = cnode;
	newnode -> next = NULL;
	cnode -> next = newnode;
	return ndata;

}

InfNData *create_node_ing(char *fname, InfNode *gr) {

	InfNode *cnode, *newnode;
	InfNData *ndata;

	if (!fname || !gr) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	cnode = gr;
	while (cnode -> next)
		cnode = cnode -> next;
	if ((newnode = malloc(sizeof(InfNode))) == NULL || (ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;
		return NULL;
	}
	newnode -> fd = ndata -> fd = cnode -> fd + 1;
	newnode -> filename = ndata -> filename = fname;
	newnode -> is_grouper = ndata -> is_grouper = false;
	newnode -> is_in_group = ndata -> is_in_group = true;
	newnode -> is_root = ndata -> is_root = false;
	newnode -> is_modified = false;
	newnode -> data = NULL;
	newnode -> prev = cnode;
	newnode -> next = NULL;
	cnode -> next = newnode;
	return ndata;

}
