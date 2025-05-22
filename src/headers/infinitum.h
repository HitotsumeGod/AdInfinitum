#ifndef __INFINITUM_H__
#define __INFINITUM_H__

#include <stdbool.h>
#include <stddef.h>
#include "fssize.h"

#define MALLOC_ERR -2
#define REALLOC_ERR -3
#define FORMAT_ERR -4
#define BAD_ARGS_ERR -5
#define NODE_CREATION_ERR -50
#define NODE_MATCH_ERR -51
#define INV_FILE_DESC_ERR -60

#ifndef __BIGFS
#ifndef __HUGEFS
typedef signed int inf_t;
#endif
#endif
#ifdef __BIGFS
typedef signed long inf_t;
#endif
#ifdef __HUGEFS
typedef signed long long inf_t;
#endif

typedef struct InfNode {
	int fd;
	char *filename;
	bool is_grouper;
	bool is_in_group;
	bool is_root;
	bool is_modified;
	char *data;
	struct InfNode *prev;
	struct InfNode *next;
} InfNode;

typedef struct {
	int fd;
	char *filename;
	bool is_grouper;
	bool is_in_group;
	bool is_root;
} InfNData;

typedef enum FSTemplate {
	SIMPLE,
	ARCHITECTURAL,
	CUSTOM
} FSTemplate;

typedef enum FMode {
	READ,
	WRITE,
	READB,
	WRITEB,
	GOD
} FMode;

extern InfNode *FSR;										//DETERMINES WHICH FS IS CURRENTLY IN USE FOR THE REST OF THE API
extern InfNode *FSP;										//THE FILESYSTEM POINTER, USED BY THE FSP API

//UNIVERSAL FS API

extern InfNode *init_inf(FSTemplate form, void *params);					//INIT A NEW INFINITUM FILESYSTEM AND RETURN THE ROOT NODE
extern bool set_fs(InfNode *fsroot);								//FAILS IF NOT PROVIDED WITH A ROOT NODE
extern bool free_inf(InfNode *fsroot, InfNode *new_fsp);					//FREES AN INF FS VIA FSP API; CAN PASS A POINTER TO THE NEW FSP LOCATION GIVEN THAT THE FUNCTION WILL ALTER THE FSP

//PRIMARY FS API (CFS)

extern InfNData *query_node_wfd(int fd);
extern InfNData *query_node_wn(char *filename);
extern InfNData *query_node_ing_wfd(int fd, InfNode *grouproot);
extern InfNData *query_node_ing_wn(char *filename, InfNode *grouproot);
extern InfNode *get_node_wfd(int fd);
extern InfNode *get_node_wn(char *filename);
extern InfNode *get_node_ing_wfd(int fd, InfNode *grouproot);
extern InfNode *get_node_ing_wn(char *filename, InfNode *grouproot);
extern size_t write_to_file(char *data, size_t to_write, InfNode *file_to_write);
extern size_t read_from_file(char **data_buffer, size_t to_read, InfNode *file_to_read);
extern InfNData *create_node(char *filename);
extern InfNData *create_node_ing(char *filename, InfNode *grouproot);
extern InfNData *create_grouper_node(char *filename);
extern InfNData *create_grouper_node_ing(char *filename, InfNode *grouproot);
extern bool insert_node(char *filename, unsigned long prev_fd);
extern bool insert_node_ing(char *filename, unsigned long prev_fd, InfNode *grouproot);
extern bool swap_node_wfd(int fd, int tfd);
extern bool swap_node_wn(char *filename, char *tfname);
extern bool unlink_node_wfd(int fd);
extern bool unlink_node_wn(char *filename);
extern bool unlink_node_ing_wfd(int fd, InfNode *grouproot);
extern bool unlink_node_ing_wn(char *filename, InfNode *grouproot);

//POINTER-BASED FS API (FSP)

extern bool move_fsp(inf_t places);
extern InfNData *query_fsp(void);
extern InfNode *get_fsp(void);
extern InfNode *open_fsp(FMode mode);
extern InfNData *create_node_fsp(char *filename);
extern bool unlink_fsp(void);

#endif //__INFINITUM_H__
