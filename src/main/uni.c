#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "infinitum.h"

InfNode *FSR, *FSP;

InfNode *init_inf(FSTemplate f, void *args) {

	InfNode *fsroot;
	char int_to_str;

	switch (f) {
	case SIMPLE:
		if ((fsroot = malloc(sizeof(InfNode))) == NULL) {
			errno = MALLOC_ERR;	
			return NULL;
		}
		fsroot -> fd = 0;
		fsroot -> filename = "ROOT";
		fsroot -> is_grouper = false;
		fsroot -> is_root = true;
		fsroot -> is_modified = false;
		fsroot -> data = NULL;
		fsroot -> prev = NULL;
		fsroot -> next = NULL;
		//set_fs(fsroot);
		/*for (int i = 1; i <= 7; i++) {
			if (sprintf(&int_to_str, "%d", i) == -1) {
				errno = FORMAT_ERR;
				return NULL;
			}
			free(create_node_fsp(&int_to_str));					//IMMEDIATELY FREE UNNEEDED INFNDATA STRUCT
			move_fsp_f(1);
		}*/
	}
	return fsroot;

}

bool set_fs(InfNode *fsroot) {

	if (!fsroot)
		return false;
	else if (!fsroot -> is_root)
		return false;
	FSR = FSP = fsroot;
	return true;

}

bool free_inf(InfNode *fsr, InfNode *ptr) {

	if (!fsr) {
		errno = BAD_ARGS_ERR;
		return false;
	}
	for (FSP = fsr; (fsr = get_fsp()) -> next != NULL; move_fsp(1)) 
		if (fsr -> prev) {	
			if (fsr -> prev -> is_modified) {
				free(fsr -> prev -> data);
			}
			free(fsr -> prev);
		}
	if (fsr) {
		if (fsr -> is_modified)
			free(fsr -> data);
		free(fsr);
	}
	FSP = ptr;
	return true;

}
