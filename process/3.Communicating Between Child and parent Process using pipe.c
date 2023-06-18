

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <pthread.h>


int main(int argc, char * argv[]){
	    // Need two File Descriptor
		int fd[2];
		// fd[0] -> Read End of pipes
		// fd[1] -> Write End of pipes
		if(pipe(fd) == -1){
			printf("An error occured in openning pipe\n");
			return 1;
		}
		int id = fork();
		if (id == -1){
			printf("Error in crating child process\n");
		}
		//child process
		if (id == 0){
			// write a variable to send its value to main process
			close(fd[0]);
			int x;
			printf("Input value: ");
			scanf("%d",&x);
			if( write(fd[1],&x,sizeof(int)) == -1){
				printf("Error Occured In writing\n");
				return 2;
			} 
			close(fd[1]);
		}
		//Main Process
		else{
			int y;
			close(fd[1]);
			if( read(fd[0],&y,sizeof(int)) == -1){
				printf("An Error Occured In File Reading\n");
				return 3;
			}
			close(fd[0]);
			printf("Inupt From Child Proccess =%d\n",y);
		}
	return 0;
}
