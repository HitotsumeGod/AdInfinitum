#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "infinitum.h"

InfNData *query_node_wfd(int fd) {

	InfNode *cnode;
	InfNData *ndata;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (fd < 0) {
		errno = INV_FILE_DESC_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
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
	if (!cnode) {
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

InfNData *query_node_wn(char *fname) {

	InfNode *cnode;
	InfNData *ndata;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (!fname) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
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
	if (!cnode) {
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

InfNData *query_node_ing_wfd(int fd, InfNode *gr) {

	InfNode *cnode;
	InfNData *ndata;
	
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (fd < 0) {
		errno = INV_FILE_DESC_ERR;
		return NULL;
	}
	if (!gr || !(cnode = gr -> next)) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;	
		return NULL;
	}
	while (cnode && cnode -> is_in_group) 
		if (cnode -> fd = fd)
			break;
		else
			cnode = cnode -> next;
	if (!cnode || !cnode -> is_in_group) {
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

InfNData *query_node_ing_wn(char *filename, InfNode *gr) {

	InfNode *cnode;
	InfNData *ndata;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (!filename || !gr || !(cnode = gr -> next)) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if ((ndata = malloc(sizeof(InfNData))) == NULL) {
		errno = MALLOC_ERR;	
		return NULL;
	}
	while (cnode && cnode -> is_in_group) 
		if (strcmp(cnode -> filename, filename) == 0)
			break;
		else
			cnode = cnode -> next;
	if (!cnode || !cnode -> is_in_group) {
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
