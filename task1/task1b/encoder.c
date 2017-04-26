
#include "util.h"

#define SYS_WRITE 4
#define SYS_READ 3
#define SYS_EXIT 1
#define SYS_OPEN 5
#define SYS_CLOSE 6

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char** argv){

	int i;
	int j;

	i = system_call(SYS_OPEN, "bb", 2, 0);
	system_call(SYS_WRITE, STDOUT, itoa(i), 1);
	// system_call(SYS_WRITE, STDOUT, "\n", 1);
	j = system_call(SYS_WRITE, i, "alon", 4);
	system_call(SYS_WRITE, STDOUT, itoa(j), 1);

	return 0;
}


/*
int main(int argc, char** argv){
	
	// system_call(SYS_WRITE,STDOUT, "hello world\n",12);
	int debug = 0;
	int fileOut = 0;
	int fileIn = 0;
	int i;
	int j;
	char c[1];
	char* sys_call;
	char* sys_ret;
	char arg[2];
	char c=0;
	char outputFileName[30];
	char* inputFileName;
	// system_call(SYS_READ,STDIN, c,1);
	
	int k;
	for(k=0; k < argc; k++){
		if((strlen(agrv[k]) == 2) && (argv[i][0] == '-') && (argv[k][1] == 'd')){
			debug = k;
		}
		if((strlen(agrv[k]) == 2) && (argv[i][0] == '-') && (argv[k][1] == 'i')){
			fileIn = k;
		}
		if((strlen(agrv[k]) == 2) && (argv[i][0] == '-') && (argv[k][1] == 'o')){
			fileOut = k;
		}
	}

	// if(argc < 2){
			// while((i = system_call(SYS_READ,STDIN, c,1)) != 0){

			// 	if(debug){

			// 		system_call(SYS_WRITE,STDERR, "system_call ", 12);
			// 		sys_call = itoa(SYS_READ);
			// 		system_call(SYS_WRITE,STDERR, sys_call, strlen(sys_call));
			// 		system_call(SYS_WRITE,STDERR, " was used. returned ", 20);
			// 		sys_ret = itoa(i);
			// 		system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			// 		system_call(SYS_WRITE,STDOUT, "\n",1);
			// 	}
				
			// 	if(c[0] >= 65 && c[0] <= 90)
			// 		c[0] += 32;
					
			// 	j = system_call(SYS_WRITE,STDOUT, c,1);
			// 	system_call(SYS_WRITE,STDOUT, "\n",1);

			// 	if(debug){

			// 		system_call(SYS_WRITE,STDERR, "system_call ", 12);
			// 		sys_call = itoa(SYS_WRITE);
			// 		system_call(SYS_WRITE,STDERR, sys_call, strlen(sys_call));
			// 		system_call(SYS_WRITE,STDERR, " was used. returned ", 20);
			// 		sys_ret = itoa(j);
			// 		system_call(SYS_WRITE,STDERR, sys_ret, strlen(sys_ret));
			// 		system_call(SYS_WRITE,STDOUT, "\n",1);
			// 	}
			// }

			// system_call(SYS_WRITE,STDOUT, "\n",1);
		// }
	// }
	// else{
		// if(argc > 2){
			
			// for(i=1; i<argc; i++){
				
				if(fileIn){
					
					system_call(SYS_OPEN, argv[fileIn+1], 0, 1);
					if(fileOut){
						system_call(SYS_OPEN, argv[fileOut+1], 0, 1);
						system_call(SYS_WRITE, argv[fileOut+1], 0, 1);
					}
					// inputFileName = argv[i+1];
					// FILE* inputFile = fopen(argv[i+1], "r");

					// if (inputFile == NULL) {
					// 	fprintf(stderr, "Can't open input file %s!\n", argv[i+1]);
					// 	return 1;
					// }

					// input = inputFile;
					
				}
				else{
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
						system_call(SYS_WRITE,STDOUT, "\n",1);

						if(debug){

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
				}
			// 	else if(strcmp(argv[i],"-o")==0){
					
			// 		fprintf(output, "Enter output file:\n");
			// 		fgets(outputFileName, 30, input);
			// 		fprintf(output, "Enter text to encode:\n");
			// 		FILE* outputFile = fopen(outputFileName, "w+");
			// 		output = outputFile;

			// 	}
			// 	else if((argv[i][0] == 43) || (argv[i][0] == 45)){
					
			// 		for(j=0; j<2; j++){
			// 			arg[j] = argv[i][j];
			// 		}
			// 	}
			// }
		// }

		if(arg[0] == 43){
			
			while((c = fgetc(input))!=EOF){

				if((c >= 97 && c <= 122) || (c >= 65 && c <= 90)){

					if(c >= 65 && c <= 90)
						c += 32;
						
					if(c+(arg[1]-48) > 122){
						c = ((c+arg[1]-48)%122)+96;
					}
					else{
						c += (arg[1]-48);
					}
				}
				fputc(c, output);
			}

		}

		else if(arg[0] == 45){
			
			while((c = fgetc(input))!=EOF){

				if((c >= 97 && c <= 122) || (c >= 65 && c <= 90)){
					if(c >= 65 && c <= 90)
						c += 32;
						
					if(c-(arg[1]-48) < 97){
						c = (c-(arg[1]-48))+26;
					}
					else{
						c -= (arg[1]-48);
					}
				}
				fputc(c, output);
			}
		}
	// }

	fclose(input);
	fclose(output);

	return 0;
}
*/