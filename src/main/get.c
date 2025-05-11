#include <string.h>
#include <errno.h>
#include "infinitum.h"

InfNode *get_node_wfd(int fd) {

	InfNode *cnode;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (fd < 0) {
		errno = INV_FILE_DESC_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	cnode = FSR;
	while (cnode) 
		if (cnode -> fd = fd)
			break;
		else
			cnode = cnode -> next;
	errno = NODE_MATCH_ERR;
	return NULL;
	
}

InfNode *get_node_wn(char *fname) {

	InfNode *cnode;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (!fname) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	cnode = FSR;
	while (cnode)
		if (strcmp(cnode -> filename, fname) == 0)
			return cnode;
		else
			cnode = cnode -> next;
	errno = NODE_MATCH_ERR;
	return NULL;

}

InfNode *get_node_ing_wfd(int fd, InfNode *gr) {

	InfNode *cnode;

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
	while (cnode -> is_in_group)
		if (cnode -> fd = fd)
			return cnode;
		else
			cnode = cnode -> next;
	errno = NODE_MATCH_ERR;
	return NULL;

}

InfNode *get_node_ing_wn(char *fname, InfNode *gr) {

	InfNode *cnode;

	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	if (!fname || !gr || !(cnode = gr -> next)) {
		errno = BAD_ARGS_ERR;
		return NULL;
	}
	///////////////////////////////////////////////////////ERRCHECK///////////////////////////////////////////////////////
	while (cnode -> is_in_group) 
		if (strcmp(cnode -> filename, fname) == 0)
			return cnode;
		else
			cnode = cnode -> next;
	errno = NODE_MATCH_ERR;
	return NULL;	

}

