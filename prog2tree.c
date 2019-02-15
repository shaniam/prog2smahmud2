
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "processtree.h"
#include <unistd.h>


int main(int argc, char *argv[])
{
	int opt;
	int numlevels=1;
	int numchildren=1;
	int n;
	int b;
	int pauses=0;
	int sleeps=0;
	int sleeping=1;
	while((opt = getopt(argc, argv, ":uM:N:ps:")) != -1){
        switch(opt){
		case 'u': 
			fprintf(stderr, "prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time]");
			return 0;
		case 'N':
			//int n;
			n=atoi(optarg);
			if (n<=4){
				numlevels=n;
			}else{
				fprintf(stderr, "must enter a value within the range [1,4]");
				return 0;
			}
			continue;
		case 'M':
			n=atoi(optarg);
			if(n<=3){
				numchildren=n;
			}
			else{
				fprintf(stderr, "must enter a value within the range[1,3]");
			
			}
			continue;
    		case 'p':
			pauses++;
			//n=atoi()
			continue;

		case 's':
			sleeping=atoi(optarg);
			sleeps++;
			continue;
	}
	}//end while
	//processTree(numlevels,numchildren);
	if (sleeps==1 && pauses==1){
                fprintf(stderr, "prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time]");
		return 0;
	}
	char numl[2];
	 pid_t pid; /* for a child process */
	int i;
	int x;
	char child[2];
        printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid()); 

	for(i=0;i<numchildren;i++) {
		//printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid()); 
		if (numlevels==1){
			break;}
		pid=fork();
        	if (pid<0){
			perror("failed fork\n");
			exit(1);
		}
        	if(pid==0){
			numlevels--;
                	sprintf(numl ,"%d", numlevels);
			sprintf(child, "%d", numchildren);
			char* args[50];
		       	args[0] = "-N";
			args[1] = numl;
			args[2]="-M";
			args[3]= child;
			args[4]= NULL;
		        execlp("./prog2tree", "./prog2tree", "-N", numl, "-M", child, NULL);
        	}
    	}
	
	if (pauses==1 && sleeps==0){
		if (numlevels>1){
			for (int i=0; i<numchildren;i++){
				wait(NULL);
			}
		}
		else{
		pause();
		}
	}

	else if(pauses==0 ){
		if (numlevels>1){
                	for(int i = 0; i < numchildren; i++){
                        	wait(NULL);
                	}
        	}
        	else{
                	sleep(sleeping);
        	}

	}
	
	//printf("EXITING")
        printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid());
	

    return 0;
	
}
