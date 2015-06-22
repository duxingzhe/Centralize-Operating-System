主要的配置工具是：Visual Studio 2013。
Ubuntu 14.10 Linux Kernel 4.0版本。
 
数据库为：SQL Server 2014，这是数据库的内部。可以使用目录中的database/ctos.bak进行恢复。必须是2014版本，否则无法恢复。

增加和编辑功能基本实现，但是其他的还要进一步实现。

调试方法：
Linux内核部分：
Set up this platform

sudo apt-get install qemu # install QEMU
sudo ln -s /usr/bin/qemu-system-i386 /usr/bin/qemu
wget https://www.kernel.org/pub/linux/kernel/v3.x/linux-4.0.tar.xz # download Linux Kernel 4.0 source code
cd ~/LinuxKernel/
mkdir rootfs
cd menu
gcc -o init linktable.c menu.c test.c -m32 -static –lpthread
cd ../rootfs
find . | cpio -o -Hnewc |gzip -9 > ../rootfs.img
qemu -kernel [your path]/linux-3.18.6/arch/x86/boot/bzImage -initrd [your path]/rootfs.img #create image file
非常抱歉，很多具体步骤已经无法记清，所以只能写个大概。
GTK+
1、编译

$gcc -o Helloworld Helloworld.c `pkg-config --cflags --libs gtk+-2.0`
2、运行

$./Helloworld
Windows:
数据库改为你自己的电脑名称\SQLEXPRESS.
必须先安装SQL Server数据库才能使用。
本操作系统的0.1版地址为Github：
https://github.com/duxingzhe/Centralize-Operating-System
具体方法可以百度。
