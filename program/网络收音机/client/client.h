#ifndef CLIENT_H__
#define CLIENT_H__

//#define DEFAULT_PLAYER "/usr/local/bin/mpg123"
#define DEFAULT_PLAYER "/home/mpg123-1.13.4/src/mpg123"

struct client_conf_st
{
	char *mgroup;
	char *rcvport;
	char *player;
};

extern struct client_conf_st client_conf;

#endif
