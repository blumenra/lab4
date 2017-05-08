

all: flame2

flame2: flame2.o  start.o  util.o
	ld -m elf_i386 start.o flame2.o util.o  -o flame2


start.o: start.s
	nasm -g -f elf start.s -o start.o -l  list.lst


flame2.o: flame2.c
	gcc -g -m32 -Wall  -c -nostdlib -fno-stack-protector flame2.c -o flame2.o


util.o: util.c  util.h
	gcc -g -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

.PHONY:
	clean

clean:
	rm -f ./*.o flame2  list.lst