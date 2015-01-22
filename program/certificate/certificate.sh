#!/bin/bash

#创建CA密钥
openssl genrsa -des3 -out ca.key 1024 #创建密钥
chmod 400 ca.key #修改权限为仅root能访问
openssl rsa -noout -text -in ca.key #查看创建的证书

#利用CA密钥自签署CA证书
openssl req -new -x509 -days 3650 -key ca.key -out ca.crt
chmod 400 ca.crt #修改权限为仅root能访问
openssl x509 -noout -text -in ca.crt #查看创建的证书

#创建服务器证书签署申请
openssl genrsa -des3 -out client.key 1024
chmod 400 server.key #修改权限为仅root能访问
openssl rsa -noout -text -in client.key #查看创建的证书

#利用证书签署申请生成请求
openssl req -new -key client.key -out client.csr
openssl req -noout -text -in client.csr #查看创建的请求

#进行证书签署
#这时候需要先设置一下openssl的配置文件
modify /usr/share/ssl/openssl.cnf 
#在创建了serial文件之后，还需要添加当前的八进制的serial,如01
#然后执行
openssl ca -keyfile ca.key -cert ca.crt -in client.csr -out client.pem

#证书撤销
openssl ca -keyfile ca.key -cert ca.crt -revoke client.pem
#这时数据库被更新证书证书被标记上撤销的标志，需要生成新的证书撤销列表
openssl ca -gencrl -keyfile ca.key -cert ca.crt -out crl/test.crl
#查看证书撤销列表
openssl crl -noout -text -in crl/test.crl
#证书撤销列表文件要在web枕垫上可以使用，必须将crldays或crlhours和crlexts加到证书中
openssl ca -gencrl -config /etc/openssl.cnf -crldays 7 -crlexts crl_ext -out crl/sopac-ca.crl

