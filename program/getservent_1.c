#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

/*扫描主机的服务数据库，并打印出所有服务的信息*/
int main()
{
	int stayopen = 1;
	struct servent *sp = 0;

	/*打开服务器数据库，准备开始扫描*/
	setservent(stayopen);

	/*逐项扫描登记的项*/
	while(1)
	{
		sp = getservent();
		if(sp != (struct servent *)0)
		{
			printf("sp->s_name = %s\n", sp->s_name);
			printf("sp->port = %d\n", sp->s_port);
			printf("sp->proto = %s\n", sp->s_proto);
		}
		else
			break;
	}

	/*关闭服务器数据库*/
	endservent();

	/*通过名字来查询telnet的端口*/
	sp = getservbyname("telnet", "tcp");
	if(sp != (struct servent *)0)
		printf("telnet's port is %d\n", ntohs(sp->s_port));
	else
		printf("Error: call 'getservbyname' faild ...\n");

	/*通过端口好来查询占用23号端口的服务器名字*/
	sp = getservbyport(htons(23), "tcp");
	if(sp != (struct servent *)0)
		printf("port 23 is %s\n", sp->s_name);
	else
		printf("Error: call 'getserbyport' faild ...\n");

	return 0;

}
