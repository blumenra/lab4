#include "../include/util.h"

#define SYS_EXIT 1
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define SYS_LSEEK 19
#define SYS_GETDENTS 141

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main (int argc , char* argv[], char* envp[])
{

	int descriptor;
	descriptor = system_call(SYS_OPEN, "greeting", 2, 0644);
	system_call(SYS_LSEEK,descriptor, 657, 0);
	system_call(SYS_WRITE,descriptor, "Mira. \n",7);
	system_call(SYS_WRITE,descriptor, "\0",1);

  return 0;
}
