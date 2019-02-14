#include "processtree.h"
#include <string.h>
#include <stdio.h>
//#include <cstdio>
//#include <cstdio>


void processTree(int levels, int children) {
	char numl[2];
	 pid_t pid; /* for a child process */
	int i;
	int x;
	char child[2];
	printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", levels, getpid(), getppid());
	//if (levels>1){
		for(i=0;i<children;i++) { 
			if (levels==1){
				break;}
			pid=fork();
        		if (pid<0){
			printf("failed fork\n");
			}
        		if(pid==0){
                		//char num1[2];
                		//levels--;
				if(levels==4){
				x=3;
				}
				else if (levels==3){
				x=2;
				}
				else if(levels==2){
					x==1;
				}

				//printf("hello");
                		sprintf(numl ,"%d", x);
				sprintf(child, "%d", children);
                		
				//execlp("./main", "./main", "-N", num1,"-M", children);
                		execlp("./main", "./main", "-N", numl, "-M", child);
        		}
			else{
				//for (i=0; i<children; i++){
					 wait(NULL);     
        			//	}
			
			}
    		}	 
	/*if(pid!=0){
	for (i=0; i<children; i++){
		
		wait(NULL);	
	//}
	}
	}*/

	
	//printf("EXITING")
        printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", levels, getpid(), getppid());
	
	return ;
}
