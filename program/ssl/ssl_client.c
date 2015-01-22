#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include <resolv.h>
#include <netinet/in.h>
#include <unistd.h>

void showcerts(SSL *ssl)
{
	X509 *cert;
	char *line;

	/*从SSL套接字中提取对方的证书信息，这些信息已经被SSL验证过了*/
	cert = SSL_get_peer_certificate(ssl);
	if(cert != NULL)
	{
		printf("数字证书信息：\n");
		/*得到证书所用者的名字*/
		line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
		printf("证书：%s\n", line);
		free(line);	

		line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
		printf("颁发者：%s\n", line);
		free(line);

		X509_free(cert);
	}else
		printf("证书无效！\n");
}

int main()
{
	int sd;
	char buf[BUFSIZ];
	SSL_CTX *ctx;
	SSL *ssl;
	struct sockaddr_in raddr;

	SSL_library_init();
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	ctx = SSL_CTX_new(SSLv23_client_method());
	if(ctx == NULL)
	{
		ERR_print_errors_fp(stdout);
		exit(1);
	}

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&raddr, sizeof(raddr));
	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(2222);
	raddr.sin_addr.s_addr = INADDR_ANY;

	if(connect(sd, (struct sockaddr *)&raddr, sizeof(raddr)) != 0)
	{
		perror("connect()");
		exit(1);
	}

	ssl = SSL_new(ctx);
	SSL_set_fd(ssl, sd);
	if(SSL_connect(ssl) == -1)
	{
		ERR_print_errors_fp(stderr);
	}else{
		printf("SSL_connect success!\n");
		showcerts(ssl);
	}

	bzero(buf, BUFSIZ + 1);
	if(SSL_read(ssl, buf, BUFSIZ) < 0)
	{
		printf("read faild!\n");
		goto finish;
	}
	printf("read success:%s\n", buf);

	bzero(buf, BUFSIZ + 1);
	strcpy(buf, "from client->server");
	if(SSL_write(ssl, buf, BUFSIZ) < 0)
	{
		printf("write faild!\n");
	}
	
finish:
		SSL_shutdown(ssl);
		SSL_free(ssl);
		close(sd);
		SSL_CTX_free(ctx);

	exit(0);
}
