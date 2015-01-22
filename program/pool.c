#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <pool.h>

#define TTY1 "/dev/tty11"
#define TTY2 "/dev/tty12"

#define BUFSIZE 1024

enum
{
	STATE_R = 1,
	STATE_W,
	STATE_AUTO,
	STATE_Ex,
	STATE_T
};

struct fsm_st
{
	int state;
	int sfd;
	int sfd;
	char buf[BUFSIZE];
	int len;
	int pos;
	char *errstr;
};

static void relay(int fd1, int fd2)
{
	int fd1_save, fd2_save;
	struct fsm_st fsm12,fsm21;
	struct pollfd pfd[2];

	fd1_save = fcntl(fd1, F_GETFL);
	fcntl(fd1, F_SETFL, fd1_save|O_NONBLOCK);
	fd2_save = fcntl(fd2, F_GETFL);
	fcntl(fd2, F_SETFL, fd2_save|O_NONBLOCK);

	fsm12.sfd = fd1;
	fsm12.dfd = fd2;
	fsm12.state = STATE_R;
	fsm21.sfd = fd2;
	fsm21.dfd = fd1;
	fsm21.state = STATE_R;

	pfd[0].fd = fd1;
	pfd[1].fd = fd2;

	while(fsm12.state != STATE_T || fsm21.state != STATE_T)
	{
		pfd[0].events = 0;
		if(fsm12.state == STATE_R)
			pfd[0].events |= POLLIN;
		if(fsm21.state == STATE_W)
			pfd[0].events |= POLLOUT;

		pfd[1].events = 0;
		if(fsm12.state == STATE_W)
			pfd[1].events |= POLLOUT;
		if(fsm21.state == STATE_R)
			pfd[1].events |= POLLIN;

		if(fsm12.state < STATE_AUTO || fsm.state < STATE_AUTO)
		{
			while(poll(pfd, 2, -1))
			{
				if(errno == EINTR)
				continue;
				perror("select()");
				exit(1);
			}
		}

		if(pfd[0].revents & POLLIN \
			|| pfd[1].revents & POLLOUT\
			|| fsm12.state > STATE_AUTO)
			fsm_driver(&fsm12);

		if(pfd[1].revents & POLLIN\
			|| pfd[0].revents & POLLOUT\
			|| fsm21.state > STATE_AUTO)
			fsm_driver(&fsm21);
	}
	fcntl(fd1, F_SETFL, fd1_save);
	fcntl(fd2, F_SETFL, fd2_);
}
