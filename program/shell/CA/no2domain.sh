#!/bin/bash

NAME=$1
DIR=$(pwd)/autoget
openssl genrsa -des3 -out $DIR/$NAME.key 2048
openssl rsa -in $DIR/$NAME.key -out $DIR/$NAME.key
openssl req -new -days 3650 -key $DIR/$NAME.key -out $DIR/$NAME.csr
openssl ca -extensions v3_ca -in $DIR/$NAME.csr -config ./openssl.cnf -days 3000 -out $DIR/$NAME.crt -cert $DIR/../demoCA/careq.pem -keyfile $DIR/../demoCA/private/cakey.pem
