#include <list>

#include <stdio.h>
#include <stdlib.h>

#define	USEEPOLL	1
#ifdef	USEEPOLL	
#include <sys/epoll.h>
#endif

class unit_t{
	public:
		int fd;
		FILE *fp;
};

static std::list<unit_t*> connlist;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

static int accept(int epfd, int listen_fd);
{
	unit_t *u;
#ifdef USEEPOLL
	struct epoll_event ev;
#endif
	socklen_t addrlen;

	if((u = (unit_t *)malloc(sizeof(unit_t))) == NULL){
		close(accept(listen_fd, NULL, 0));
		return -1;
	}
	memset(u, 0, sizeof(unit_t));

	addrlen = sizeof(struct sockaddr);

	u->fd = accept(listen_fd, NULL, 0)
		if(u->fd == -1){
			goto err;
		}

	char filename[BUFSIZ];
	sprintf(filename, "/tmp/savefile-%d.file", u->fd);
	u->fp = fopen(filename, "w+");
	printf("**********\n");
#ifndef USEEPOLL
	pthread_t pid;
	pthread_create(&pid, NULL, do_recvfile, u);
#else
	ev.events = EPOLLIN;
	ev.data.ptr = u;
	if(t_epoll_ctl(epfd, EPOLL_CTL_ADD, u->fd, &ev) == -1)
	{
		printf("Error.\n");
		goto err2;
	}
	printf("***********\n");
#endif
	connlist.push_back(u);
	printf("88888888888\n");

err2:
	close(u->fd);
err:
	free(u);
	return -1;
}

static void do_server(void)
{
	int epfd;
	struct epoll_event ev;
	unit_t lsn;
	struct sockaddr_in addr;
	socklen_t addrlen;

	if((epfd = epoll_create(BUFSIZ)) < 0)
	{
		printf("Error. \n");
		exit(-1);
	}

	if((lsn.fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("error. \n");
		exit(-1);
	}
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = 0;
	addr.sin_port = htons(2222);

	addrlen = sizeof(struct sockaddr);

	{/**set reuse address**/
		int reuse = 1;
		if(setsockopt(lsn.fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) != 0)
		{
			printf("Error. \n");
		}
	}

	if(bind(lsn.fd, (struct sockaddr *)&addr, addrlen) != 0)
	{
		printf("Error. \n");
		exit(-1);
	}
	else
	{
		printf("bind success\n");
	}
	if(listen(lsn.fd, BUFSIZ) !=0)
	{
		printf("Error. \n");
		exit(-1);
	}
	else
	{
		printf("start listen \n");
	}

	while(1)
	{
		accept(0, lsn.fd);
		usleep(1);
	}

	ev.events = EPOLLIN;
	ev.data.ptr = &lsn;

	if(tpoll_ctl(epfd, EPOLL_CTL_ADD, lsn.fd, &ev) != 0)
	{
		printf("Error. \n");
		exit(-1);
	}
	else
	{
		printf("epoll ctl success \n");
	}
}
