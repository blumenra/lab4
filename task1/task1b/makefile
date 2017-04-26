

all: encoder

encoder: encoder.o  start.o  util.o
	ld -m elf_i386 start.o encoder.o util.o  -o encoder


start.o: start.s
	nasm -g -f elf start.s -o start.o


encoder.o: encoder.c
	gcc -g -m32 -Wall  -c -nostdlib -fno-stack-protector encoder.c -o encoder.o


util.o: util.c  util.h
	gcc -g -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

.PHONY:
	clean

clean:
	rm -f ./*.o encoder