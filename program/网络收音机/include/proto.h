#ifndef PRPTO_H_
#define PRPTO_H_
#include <inttypes.h>

#define DEFAULT_MGROUP		"224.2.2.2"
#define DEFAULT_RCVPORT		"1992"

#define NR_CHN		200
#define CHNID_LIST	0
#define MINCHNID	1
#define MAXCHNID	(MINCHNID+NR_CHN-1)

typedef uint8_t chnid_t;

#define MAX_MSG			(65536-20-8)
#define MAX_DATA		(MAX_MSG-sizeof(chnid_t))
#define MAX_ENTRY		(MAX_MSG-sizeof(chnid_t))
#define MAX_ENTRY_ONE	(MAX_ENTRY/200-sizeof(chnid_t))

struct msg_channel_st
{
	chnid_t chnid;		/*[MINCHNID,MAXCHNID]*/
	uint32_t datasize;
	uint8_t data[1];
}__attribute__((packed));

struct list_entry_st
{
	chnid_t chnid;
	uint8_t desc[MAX_ENTRY_ONE];
}__attribute__((packed));

struct msg_list_st
{
	chnid_t chnid;      /*CHNID_LIST --> 0*/
	uint8_t length;
	struct list_entry_st entry[1];
}__attribute__((packed));

#endif
