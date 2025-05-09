#ifndef __INFINITUM_H__
#define __INFINITUM_H__

#include <stdbool.h>

#define MALLOC_ERR -2
#define REALLOC_ERR -3
#define NODE_CREATION_ERR -50
#define NODE_MATCH_ERR -51
#define INV_FILE_DESC_ERR -60

typedef struct InfNode {
	int fd;
	char *filename;
	bool is_grouper;
	bool is_in_group;
	bool is_root;
	void *data;
	struct InfNode *prev;
	struct InfNode *next;
} InfNode;

typedef struct {
	int fd;
	char *filename;
	bool is_grouper;
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

extern InfNode *FSR;							//DETERMINES WHICH FS IS CURRENTLY IN USE FOR THE REST OF THE API
extern InfNode *FSP;							//THE FILESYSTEM POINTER, USED BY THE FSP API

//UNIVERSAL FS API

extern InfNode *init_inf(FSTemplate form, void *params);		//INIT A NEW INFINITUM FILESYSTEM AND RETURN THE ROOT NODE
extern bool set_fs(InfNode *fsroot);					//FAILS IF NOT PROVIDED WITH A ROOT NODE
extern void free_inf(InfNode *fsroot);					//FREES AN INF FS VIA FSP API; ENSURES FSP IS SET TO ORIGINAL VALUE BEFORE RETURNING

//PRIMARY FS API (CFS)

extern InfNData *query_node_wfd(int fd);
extern InfNData *query_node_wn(char *filename);
extern InfNData *query_node_ing_wfd(int fd, InfNode *grouproot);
extern InfNData *query_node_ing_wn(char *filename, InfNode *grouproot);
extern InfNode *get_node_wfd(int fd);
extern InfNode *get_node_wn(char *filename);
extern InfNode *get_node_ing_wfd(int fd, InfNode *grouproot);
extern InfNode *get_node_ing_wn(char *filename, InfNode *grouproot);
extern InfNode *open_file_wfd(int fd, FMode mode);
extern InfNode *open_file_wn(char *filename, FMode mode);
extern InfNode *open_file_ing_wfd(int fd, InfNode *grouproot, FMode mode);
extern InfNode *open_file_ing_wn(char *filename, InfNode *grouproot, FMode mode);
extern InfNData *create_node(char *filename, long long index, InfNode *grouproot);
extern bool insert_node_wfd(int fd, long long index);
extern bool insert_node_wn(char *filename, long long index);
extern bool insert_node_ing_wfd(int fd, long long index, InfNode *grouproot);
extern bool insert_node_ing_wn(char *filename, long long index, InfNode *grouproot);
extern bool swap_node_wfd(int fd, int tfd);
extern bool swap_node_wn(char *filename, char *tfname);
extern bool unlink_node_wfd(int fd);
extern bool unlink_node_wn(char *filename);
extern bool unlink_node_ing_wfd(int fd, InfNode *grouproot);
extern bool unlink_node_ing_wn(char *filename, InfNode *grouproot);

//POINTER-BASED FS API (FSP)

extern void move_fsp_f(long long places);
extern void move_fsp_b(long long places);
extern InfNData *query_fsp(void);
extern InfNode *get_fsp(void);
extern InfNode *open_fsp(FMode mode);
extern InfNData *create_node_fsp(char *filename);
extern bool unlink_fsp(void);

#endif //__INFINITUM_H__
