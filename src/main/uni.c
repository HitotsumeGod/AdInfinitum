#include <stdlib.h>
#include <errno.h>
#include "infinitum.h"

InfNode *FSR, *FSP;

InfNode *init_inf(FSTemplate f, void *args) {

	InfNode *fsroot;

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
		fsroot -> data = NULL;
		fsroot -> prev = NULL;
		fsroot -> next = NULL;
		break;
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
