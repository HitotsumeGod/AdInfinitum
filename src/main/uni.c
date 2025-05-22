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
	}
	return fsroot;

}

bool set_fs(InfNode *fsroot) {

	if (!fsroot)
		return false;
	else if (!fsroot -> is_root)
		return false;
	FSP = FSR = fsroot;
	return true;

}

bool free_inf(InfNode *fsr, InfNode *ptr) {

	InfNode *tofree;
	
	if (!fsr) {
		errno = BAD_ARGS_ERR;
		return false;
	}
	//SINCE MOVE_FSP SHOULD NEVER ADVANCE TO A NULL POSITION, WE ADVANCE UP TO THE LAST NODE AND THEN TERMINATE
	for (FSP = fsr; (fsr = get_fsp()) -> next != NULL; move_fsp(1))	{
		if (fsr -> prev) {	
			if (fsr -> prev -> is_modified) {
				free(fsr -> prev -> data);
			}
			free(fsr -> prev);
		}
	}
	//SO NOW WE NEED TO FREE THE FINAL NODE AND ITS PREDECESSOR MANUALLY
	if (fsr -> prev -> is_modified)
		free(fsr -> prev -> data);
	free(fsr -> prev);
	if (fsr -> is_modified)
		free(fsr -> data);
	free(fsr);
	if (ptr)
		FSP = ptr;
	return true;

}
