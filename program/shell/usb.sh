#!/bin/bash

quit()
{
	clear
	echo "************************************"
	echo "***    thank you to Good bye!    ***"
	exit 0
}

mountusb()
{
	/sbin/fdisk -l |grep /dev/sd
	echo -e "Please Enter the device name of usb as shown above:\c"
	read PARAMETER
	mount /dev/$PARAMETER /mnt/usb
}

display()
{
	clear
	ls -la /mnt/usb
}

umountusb()
{
	clear
	umount /mnt/usb
}

cpdisktousb()
{
	clear
	echo -e "Please Enter the filename to be Copide (unrrent directory):\c"
	read FILE
	echo "Copying, please wait!"
	cp $FILE /mnt/usb
}

cpusbtodisk()
{
	clear
	echo -e "Please Enter the filename to be Cppide in USB:\c"
	read FILE
	echo "Copying, Please wait!"
	cp /mnt/usb/$FILE .
}

clear
while true
do
echo "============================================="
echo "***      LINUX USB MANAGE PROGRAM       ***"
echo "         1-MOUNT USB                       "
echo "         2-UMOUNT USB                      "
echo "         3-DISPLAY USB INFORMATION         "
echo "         4-COPY FILE IN DISK TO USB        "
echo "         5-COPY FILE IN USB TO DISK        "
echo "         0-EXIT                            "
echo -e "Please Enter a Choice(0-5):\c"

read CHOICE
case $CHOICE in
	1)mountusb;
	;;
	2)umountusb;
	;;
	3)display;
	;;
	4)cpdisktousb;
	;;
	5)cpusbtodisk;
	;;
	0)quit;
	;;
	*)echo "Invalid Choice! Corrent Choice is(0-5)";
clear
	;;

esac
sleep 4
clear
done
