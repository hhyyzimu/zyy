main:main.o module1.o module2.o
	gcc main.o module1.o module2.o -o main
main.o:main.c head1.h head2.h common_head.h
	gcc -c main.c
module1.o:module1.c head1.h
	gcc -c module1.c
module2.o:module2.c head2.h
	gcc -c module2.c
