#!/bin/bash

DIR=/root/ssl.test2
mkdir -p $DIR/demoCA/{private,newcerts}
touch $DIR/demoCA/index.txt
echo 01 > $DIR/demoCA/serial
openssl genrsa -des3 -out $DIR/demoCA/private.pem 2048
openssl req -new -x509 -days 3650 -key $DIR/demoCA/private/cakey.pem -out $DIR/demoCA/careq.pem
