
#include "util.h"

#define SYS_EXIT 1
#define SYS_READ 3
#define SYS_WRITE 4
#define SYS_OPEN 5
#define SYS_CLOSE 6

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
	int fileOutPos = 0;
	int fileInPos = 0;
	int rFileDescriptor = 0;
	int wFileDescriptor = 1;
	int ret;
	char c[1];

	
	int k;
	for(k=0; k < argc; k++){
		if((strlen(argv[k]) == 2) && (argv[k][0] == '-') && (argv[k][1] == 'd')){
			debug = k;
		}
		if((strlen(argv[k]) == 2) && (argv[k][0] == '-') && (argv[k][1] == 'i')){
			fileInPos = k;
		}
		if((strlen(argv[k]) == 2) && (argv[k][0] == '-') && (argv[k][1] == 'o')){
			fileOutPos = k;
		}
	}

	if(fileInPos){
		
		ret = system_call(SYS_OPEN, argv[fileInPos+1], 2, 0644);
		rFileDescriptor = ret;

		useDebugger(SYS_OPEN, ret, debug);

		if(rFileDescriptor <= 0){
			system_call(SYS_WRITE,STDERR, "The file does not exists. exiting...", 36);
			system_call(SYS_WRITE,STDOUT, "\n",1);
			
			ret = system_call(SYS_EXIT, 0, 0, 0);
			useDebugger(SYS_OPEN, ret, debug);
		}
	}

	if(fileOutPos){

		ret = system_call(SYS_OPEN, argv[fileOutPos+1], 102, 0644);
		wFileDescriptor = ret;
		useDebugger(SYS_OPEN, ret, debug);
	}


	if(debug){

		char* sys_ret;

		system_call(SYS_WRITE,STDERR, "The input file path is: ", 24);
		if(rFileDescriptor == 0)
			system_call(SYS_WRITE,STDERR, "stdin\n", 6);
		else{
			sys_ret = argv[fileInPos+1];
			system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			system_call(SYS_WRITE,STDERR, "\n", 1);
		}


		system_call(SYS_WRITE,STDERR, "The output file path is: ", 25);
		if(wFileDescriptor == 1)
			system_call(SYS_WRITE,STDERR, "stdout\n", 7);
		else{

			sys_ret = argv[fileOutPos+1];
			system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			system_call(SYS_WRITE,STDERR, "\n", 1);
		}
	}
		
	while((ret = system_call(SYS_READ,rFileDescriptor, c,1)) > 0){

		useDebugger(SYS_READ, ret, debug);

		
		if(c[0] >= 'A' && c[0] <= 'Z')
			c[0] += 32;
			
		ret = system_call(SYS_WRITE,wFileDescriptor, c,1);
		
		if(debug && (wFileDescriptor == STDOUT))
			system_call(SYS_WRITE,STDOUT, "\n",1);

		useDebugger(SYS_WRITE, ret, debug);
	}


	ret = system_call(SYS_CLOSE, rFileDescriptor);
	useDebugger(SYS_CLOSE, ret, debug);
	
	ret = system_call(SYS_CLOSE, wFileDescriptor);
	useDebugger(SYS_CLOSE, ret, debug);

	return 0;
}
