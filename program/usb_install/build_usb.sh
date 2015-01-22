#!/bin/bash



# 8GB usb disk
DISK=/dev/sdc
NUM=2

step=0

let step++;
echo "$step. check disks"

if [ "`fdisk -l 2>/dev/null | grep $DISK`" = "" ]; then
	echo "Can't find disk $DISK" && exit -1;
fi

let step++;
echo "$step. umount all the disks"
umount ${DISK}  > /dev/null 2>&1
umount ${DISK}1 > /dev/null 2>&1
umount ${DISK}2 > /dev/null 2>&1

let step++;
echo "$step. fdisk."
dd if=/dev/zero of=$DISK bs=1M count=1 > /dev/null 2>&1


# sdb1 3G for vfat
# sdb2 2G for installer os, label=SmartOS_IU
# sdb3 2G for smartgrid os, label=SmartOS_FU
fdisk $DISK > /dev/null 2>&1 << FDISKEOF
n
p
1

+3G
n
p
2

+2G
n
p
3


t
1
b
w
q
E
FDISKEOF


let step++;
echo "$step-1. format ${DISK}1"
mkfs.vfat ${DISK}1 >/dev/null 2>&1
echo "$step-2. format ${DISK}2"
mkfs.ext3 ${DISK}2 >/dev/null 2>&1
echo "$step-3. format ${DISK}3"
mkfs.ext3 ${DISK}3 >/dev/null 2>&1

let step++;
echo "$step. change label"
e2label ${DISK}2 SmartOS_IU
e2label ${DISK}3 SmartOS_FU

let step++;
echo "$step. copy smartos_installer to SmartOS_IU"
mount ${DISK}2 tobe_mount > /dev/null 2>&1
tar zxf smartos_installer.tar.gz -C tobe_mount
cp -af install.sh tobe_mount/root/smartgrid_installer.sh
sync

let step++;
echo "$step. write fstab"
UUID2=`blkid ${DISK}1 -s UUID | awk -F\" '{print $2}'`
cat > tobe_mount/etc/fstab << FSTABEOF
LABEL=SmartOS_IU        /                       ext3    defaults        0 0
LABEL=SmartOS_FU        /mnt/usb3               ext3    defaults        0 0
UUID=$UUID2             /mnt/usb1               vfat    defaults        0 0
tmpfs                   /dev/shm                tmpfs   defaults        0 0
devpts                  /dev/pts                devpts  gid=5,mode=620  0 0
sysfs                   /sys                    sysfs   defaults        0 0
proc                    /proc                   proc    defaults        0 0
FSTABEOF
sync

let step++;
echo "$step. install grub"
grub > /dev/null 2>&1 << GRUBEOF
root (hd$NUM,1)
setup (hd$NUM)
quit
GRUBEOF

sync

let step++;
echo "$step. copy smartgrid.tar.gz & boot.tar.gz to SmartOS_FU"
umount ${DISK}2 > /dev/null 2>&1
mount ${DISK}3 tobe_mount > /dev/null 2>&1
cp -af smartgrid.tar.gz boot.tar.gz tobe_mount

umount ${DISK}3 > /dev/null 2>&1

if [ "`ls tobe_install/*.bin`" != "" ]; then
	mount ${DISK}1 tobe_mount > /dev/null 2>&1;
	cp -af tobe_install/*.bin{,.md5} tobe_mount
	sync
	umount ${DISK}1 > /dev/null 2>&1
fi

let step++;
echo "$step. umount all the disks."
umount ${DISK}3 > /dev/null 2>&1
umount ${DISK}2 > /dev/null 2>&1
umount ${DISK}1 > /dev/null 2>&1

umount ${DISK}3 > /dev/null 2>&1
umount ${DISK}2 > /dev/null 2>&1
umount ${DISK}1 > /dev/null 2>&1

let step++;
echo "$step. install ok."

