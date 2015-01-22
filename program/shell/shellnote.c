1、#！				当一个文件中开头的两个字符是它时，内核会扫描该行其余的部分，看是否存在可用来执行程序的解释器的完整路径。
#！/bin/csh -f //包括解释器的完整路径和命令行

2、变量
	字母，下划线，数字,和普通变量一样
	变量的值可以是空值NULL

3、给变量赋值：
	单行可进行多次赋值：first=a		middle=b		last=c
	值中包含空格时使用引号：fullname="hello world"
	变量作为第二个变量的新值时不需要双引号：oldname=$fullname
	几个变量连起来时需要双引号：fullname="$first $middle $last"

4、echo将参数打印到标准输出，参数间以一个空格隔开，会自动提供一个换行符
	echo -n conststr 忽略结尾的换行符
	
5、重定向
	program < file 将program的标准输入改为file，对目标文件会新建或覆盖
	program > file 将program的标准输出改为file，对目标文件会新建或覆盖
	program >> file 将program的标准输出附加到file的结尾
	program1 | program2 将program1的标准输出改为program2的标准输入




