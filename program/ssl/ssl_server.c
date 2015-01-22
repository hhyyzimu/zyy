/*
	生成服务器端私钥，用于加密key文件：
	openssl genrsa  -out privkey.pem 2048/1024
	生成1024或2048位的密钥

	openssl req -new -x509 -key privkey.pem -out cacert.pem -days 1095
	证书的申请机构和颁发机构都是自己，用密钥privkey.pem生成一个数字证书cacert.pem, 控制有效期限为1095天，默认为30天

	gcc -Wall ssl_server.c -o server -lssl -lcrypto
	gcc -Wall ssl_client.c -o client -lssl -lcrypto
*/
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

int main()
{
	SSL_CTX *ctx;
	int sd, new_sd;
	char buf[BUFSIZ];
	socklen_t len;
	struct sockaddr_in laddr, raddr;

	SSL_library_init();
	OpenSSL_add_ssl_algorithms();
	SSL_load_error_strings();

	ctx = SSL_CTX_new(SSLv23_server_method());
	if(ctx == NULL){
		ERR_print_errors_fp(stdout);
		exit(1);
	}

	//SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);//设置证书验证方式
	
	//SSL_CTX_load_verify_locations(ctx, "cacert.pem", "./");//加载证书
	if(SSL_CTX_use_certificate_file(ctx, "cacert.pem", SSL_FILETYPE_PEM) <= 0)
	{
		ERR_print_errors_fp(stdout);
		exit(1);
	}

	if(SSL_CTX_use_PrivateKey_file(ctx, "privkey.pem", SSL_FILETYPE_PEM) <= 0)
	{
		ERR_print_errors_fp(stdout);
		exit(1);
	}

	if(!SSL_CTX_check_private_key(ctx))
	{
		ERR_print_errors_fp(stdout);
		exit(1);
	}

	if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket()");
		exit(1);
	}

	bzero(&laddr, sizeof(laddr));
	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(2222);
	laddr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sd, (struct sockaddr *)&laddr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	if(listen(sd, 200) < 0)
	{
		perror("listen()");
		exit(1);
	}

	while(1){
		SSL *ssl;
		len = sizeof(struct sockaddr); 
		if((new_sd = accept(sd, (struct sockaddr *)&raddr, &len)) < 0)
		{
			perror("accept()");
			exit(1);
		}

		ssl = SSL_new(ctx);
		SSL_set_fd(ssl, new_sd);

		if(SSL_accept(ssl) == -1)
		{
			perror("accept");
			close(new_sd);
			break;
		}

		bzero(buf, BUFSIZ + 1);
		strcpy(buf, "server->client");
		if(SSL_write(ssl, buf, BUFSIZ) < 0)
		{
			printf("fail!\n");
			goto finish;
		}

		bzero(buf, BUFSIZ + 1);
		if(SSL_read(ssl, buf, BUFSIZ) < 0)
		{
			printf("SSL_read fail!\n");
			goto finish;
		}
		printf("success:%s\n", buf);

	finish:
			SSL_shutdown(ssl);
			SSL_free(ssl);
			close(new_sd);
	}

	close(sd);
	SSL_CTX_free(ctx);
	exit(0);
}
