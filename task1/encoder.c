
#include "util.h"

#define SYS_WRITE 4
#define SYS_READ 3
#define SYS_EXIT 1

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char** argv){
	
	// system_call(SYS_WRITE,STDOUT, "hello world\n",12);
	int debug = 0;
	int i;
	int j;
	char c[1];
	char* sys_call;
	char* sys_ret;
	
	if((argv[1] != 0) && (argv[1][0] == '-') && ((argv[1][1] == 'd'))){
		debug = 1;
	}


	while((i = system_call(SYS_READ,STDIN, c,1)) != 0){

		if(debug){

			system_call(SYS_WRITE,STDERR, "system_call ", 12);
			sys_call = itoa(SYS_READ);
			system_call(SYS_WRITE,STDERR, sys_call, strlen(sys_call));
			system_call(SYS_WRITE,STDERR, " was used. returned ", 20);
			sys_ret = itoa(i);
			system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			system_call(SYS_WRITE,STDOUT, "\n",1);
		}
		
		if(c[0] >= 65 && c[0] <= 90)
			c[0] += 32;
			
		j = system_call(SYS_WRITE,STDOUT, c,1);

		if(debug){

			system_call(SYS_WRITE,STDOUT, "\n",1);
			system_call(SYS_WRITE,STDERR, "system_call ", 12);
			sys_call = itoa(SYS_WRITE);
			system_call(SYS_WRITE,STDERR, sys_call, strlen(sys_call));
			system_call(SYS_WRITE,STDERR, " was used. returned ", 20);
			sys_ret = itoa(j);
			system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			system_call(SYS_WRITE,STDOUT, "\n",1);
		}
	}

	system_call(SYS_WRITE,STDOUT, "\n",1);
	





	// int i;
	// int j;
	// char arg[2];
	// char c=0;
	// char outputFileName[30];
	// FILE* input = stdin;
	// FILE* output = stdout;


	// if(argc < 2){

	// 	while((c = fgetc(input))!=(EOF)){

	// 		if(c >= 65 && c <= 90)
	// 			c += 32;
				
	// 		fputc(c, output);
	// 	}
	// }
	// else{
	// 	if(argc > 2){
			
	// 		for(i=1; i<argc; i++){
				
	// 			if(strcmp(argv[i],"-i")==0){
					
	// 				FILE* inputFile = fopen(argv[i+1], "r");

	// 				if (inputFile == NULL) {
	// 					fprintf(stderr, "Can't open input file %s!\n", argv[i+1]);
	// 					return 1;
	// 				}

	// 				input = inputFile;
					
	// 			}
	// 			else if(strcmp(argv[i],"-o")==0){
					
	// 				fprintf(output, "Enter output file:\n");
	// 				fgets(outputFileName, 30, input);
	// 				fprintf(output, "Enter text to encode:\n");
	// 				FILE* outputFile = fopen(outputFileName, "w+");
	// 				output = outputFile;

	// 			}
	// 			else if((argv[i][0] == 43) || (argv[i][0] == 45)){
					
	// 				for(j=0; j<2; j++){
	// 					arg[j] = argv[i][j];
	// 				}
	// 			}
	// 		}
	// 	}

	// 	if(arg[0] == 43){
			
	// 		while((c = fgetc(input))!=EOF){

	// 			if((c >= 97 && c <= 122) || (c >= 65 && c <= 90)){

	// 				if(c >= 65 && c <= 90)
	// 					c += 32;
						
	// 				if(c+(arg[1]-48) > 122){
	// 					c = ((c+arg[1]-48)%122)+96;
	// 				}
	// 				else{
	// 					c += (arg[1]-48);
	// 				}
	// 			}
	// 			fputc(c, output);
	// 		}

	// 	}

	// 	else if(arg[0] == 45){
			
	// 		while((c = fgetc(input))!=EOF){

	// 			if((c >= 97 && c <= 122) || (c >= 65 && c <= 90)){
	// 				if(c >= 65 && c <= 90)
	// 					c += 32;
						
	// 				if(c-(arg[1]-48) < 97){
	// 					c = (c-(arg[1]-48))+26;
	// 				}
	// 				else{
	// 					c -= (arg[1]-48);
	// 				}
	// 			}
	// 			fputc(c, output);
	// 		}
	// 	}
	// }

	// fclose(input);
	// fclose(output);





	return 0;
}