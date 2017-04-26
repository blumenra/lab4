

all: encoder

encoder: encoder.o  start.o
	ld -m elf_i386 start.o encoder.o -o encoder


start.o: start.s
	nasm -g -f elf start.s -o start.o


encoder.o: encoder.c
	gcc -g -m32 -Wall  -c -nostdlib -fno-stack-protector encoder.c -o encoder.o


.PHONY:
	clean

clean:
	rm -f ./*.o encoder