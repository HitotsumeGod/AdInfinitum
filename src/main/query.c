#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "infinitum.h"

InfNData *query_node_wfd(int fd) {

	InfNode *cnode;
	InfNData *ndata;

	cnode = FSR;
	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;	
		return NULL;
	}
	while (cnode) 
		if (cnode -> fd = fd)
			break;
		else
			cnode = cnode -> next;
	ndata -> fd = cnode -> fd;
	ndata -> filename = cnode -> filename;
	ndata -> is_grouper = cnode -> is_grouper;
	ndata -> is_in_group = cnode -> is_in_group;
	ndata -> is_root = cnode -> is_root;
	return ndata;

}

InfNData *query_node_wn(char *fname) {

	InfNode *cnode;
	InfNData *ndata;

	cnode = FSR;
	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;	
		return NULL;
	}
	while (cnode) 
		if (strcmp(cnode -> filename, fname) == 0)
			break;
		else
			cnode = cnode -> next;
	ndata -> fd = cnode -> fd;
	ndata -> filename = cnode -> filename;
	ndata -> is_grouper = cnode -> is_grouper;
	ndata -> is_in_group = cnode -> is_in_group;
	ndata -> is_root = cnode -> is_root;
	return ndata;

}

InfNData *query_node_ing_wfd(int fd, InfNode *gr) {

	InfNode *cnode;
	InfNData *ndata;

	if (!gr || !(cnode = gr -> next)) {
		errno = NULL_ERR;
		return NULL;
	}
	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;	
		return NULL;
	}
	while (cnode -> is_in_group) 
		if (cnode -> fd = fd)
			break;
		else
			cnode = cnode -> next;
	if (!cnode) {
		free(ndata);
		errno = NODE_MATCH_ERR;
		return NULL;
	}
	ndata -> fd = cnode -> fd;
	ndata -> filename = cnode -> filename;
	ndata -> is_grouper = cnode -> is_grouper;
	ndata -> is_in_group = cnode -> is_in_group;
	ndata -> is_root = cnode -> is_root;
	return ndata;

}
