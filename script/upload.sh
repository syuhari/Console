#!/bin/sh

if [ $# -lt 2 ]; then
	echo "IPアドレスとアップロードするファイルを指定してください"
	echo "usage : ./upload.sh ipaddress filename"
	exit 1
fi

path=$2
filename=${path##*/}

file=`cat $2 | base64`

commandline()
{
sleep 1; echo "upload $filename $file"
sleep 5;
}

commandline | telnet $1 6010
