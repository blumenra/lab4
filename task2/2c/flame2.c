
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

extern void infection();


typedef struct ent {
	int inode;
	int offset;
	short len;
	char buf[1];
} ent;


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

int printParam(char* param, char* text, int textLen){

		system_call(SYS_WRITE, STDOUT, text, textLen);
		system_call(SYS_WRITE, STDOUT, param, strlen(param));

		return 0;
}



int main(int argc, char** argv){
	
	int debug = 0;
	int sFlagPos = 0;
	char buf[8192];
	ent *entp = (ent*) buf;	
	int ret = 0;
	int acc = 0;
	int k;

	for(k=0; k < argc; k++){
		if((strlen(argv[k]) == 2) && (argv[k][0] == '-') && (argv[k][1] == 'd')){
			debug = k;
		}
		if((strlen(argv[k]) == 2) && (argv[k][0] == '-') && (argv[k][1] == 's')){
			sFlagPos = k;
		}
	}

	system_call(SYS_WRITE,STDOUT, "Flame 2 strikes!\n", 17);
	ret = system_call(SYS_OPEN, "./", 0, 0);
	
	if(ret < 0)
		system_call(SYS_EXIT, 0x55, 0, 0);
	
	
	system_call(SYS_GETDENTS, ret, buf, 8192);

	while(entp->len > 0){

		if(sFlagPos){
			char* name = entp->buf;
			if(name[strlen(name)-1] == *argv[sFlagPos+1]){

				printParam(name, "", 0);
				if(debug){

					printParam(itoa(entp->len), ", size: ", 8);
				}
				system_call(SYS_WRITE,STDERR, "\n",1);
			}
		}
		else{

			printParam(entp->buf, "", 0);
			if(debug){

				printParam(itoa(entp->len), ", size: ", 8);
			}
			system_call(SYS_WRITE,STDERR, "\n",1);
		}


		acc += entp->len;
		entp = (ent*) (buf + acc);
	}

	return 0;
}
