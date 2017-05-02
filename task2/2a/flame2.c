
#include "util.h"

#define SYS_EXIT 1
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6
#define SYS_GETDENTS 141

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int useDebugger(int sys_call_param, int sys_ret_param, int debug){

	char* sys_call;
	char* sys_ret;

	if(debug){
		system_call(SYS_WRITE,STDERR, "system_call ", 12);
		sys_call = itoa(sys_call_param);
		system_call(SYS_WRITE,STDERR, sys_call, strlen(sys_call));
		system_call(SYS_WRITE,STDERR, " was used. returned ", 20);
		sys_ret = itoa(sys_ret_param);
		system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
		system_call(SYS_WRITE,STDERR, "\n",1);
	}

	return 0;
}

int main(int argc, char** argv){
	
	int debug = 0;
	return 0;
}
