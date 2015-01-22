#include <stdio.h>
#include <stdlib.h>

#define USEEPOLL	1

#ifdef	USEEPOLL	
#include <sys/epoll.h>
#endif

class unit_t{
	public:
		int fd;
		FILE *fp;
};

static std::list<unit_t*>	connlist;
static const char *target = "192.168.10.51:2222";

static void do_client()
{

}
