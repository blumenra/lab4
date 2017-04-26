

all: bin/task0

bin/task0: bin/main.o  bin/start.o  bin/util.o
	ld -m elf_i386 bin/start.o bin/main.o bin/util.o -o bin/task0


bin/start.o: obj/start.s
	nasm -g -f elf obj/start.s -o bin/start.o


bin/main.o: src/main.c
	gcc -g -m32 -Wall -ansi -c -nostdlib -fno-stack-protector src/main.c -o bin/main.o


bin/util.o: src/util.c  include/util.h
	gcc -g -m32 -Wall -ansi -c -nostdlib -fno-stack-protector src/util.c -o bin/util.o


.PHONY:
	clean

clean:
	rm -f bin/*.o bin/task0