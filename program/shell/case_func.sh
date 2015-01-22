#!/bin/sh

unload(){
	echo "unload";
}

uninstall(){
	echo "uninstall"
}

install(){
	echo "install"
}

load(){
	echo "load"
}

setup(){
	read x

case $x in
unload)
	unload
	;;
load)
	load
	;;
uninstall)
	uninstall
	;;
install)
	install
	;;
*)
	echo "valid responses are load unload install uninstall"
	;;
esac
}
setup
