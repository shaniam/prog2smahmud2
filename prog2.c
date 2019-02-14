#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "processtree.h"
#include <unistd.h>
int main(int argc, char *argv[])
{
	int opt;
    // put ':' in the starting of the
    // string so that program can
    //distinguish between '?' and ':'
	int numlevels=1;
	int numchildren=1;
	int n;
	//printf("hello");
      //printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid());
	//printf("hello");
    while((opt = getopt(argc, argv, ":uM:N:")) != -1)
    {
        switch(opt)
        {
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
			}
		case 'M':
			n=atoi(optarg);
			if(n<=3){
				numchildren=n;
			}
			else{
				fprintf(stderr, "must enter a value within the range[1,3]");
			}
    		}
	}
	//processTree(numlevels,numchildren);
	char numl[2];
	 pid_t pid; /* for a child process */
	int i;
	int x;
	char child[2];
	for(i=0;i<numchildren;i++) {
		printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid()); 
		if (numlevels==1){
			break;}
		pid=fork();
        	if (pid<0){
			printf("failed fork\n");
		}
        	if(pid==0){
                	//char num1[2];
                	//levels--;
			if(numlevels==4){
				x=3;
			}
			else if (numlevels==3){
				x=2;
			}
			else if(numlevels==2){
					x=1;
			}

				//printf("hello");
                		sprintf(numl ,"%d", x);
				sprintf(child, "%d", numchildren);
		               	//printf("%s",numl);
				//printf("%s", child);
				//execlp("./main", "./main", "-N", num1,"-M", children);
                		execlp("./main", "./main", "-N", numl, "-M", child);
				//printf("whats up");
        	}
		else{
			//for (int i=0; i<numchildren; i++){
			 wait(NULL);     
			//}
			}
    	}	 

	
	//printf("EXITING")
        printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numlevels, getpid(), getppid());
	

    return 0;

}

