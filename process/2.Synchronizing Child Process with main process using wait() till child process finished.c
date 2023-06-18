

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <pthread.h>


int main(int argc, char * argv[]){
		//Create A child process with process it 0
		int id = fork();
		int n;
		if (id == 0){
			n = 1;
		}
		else{
			n = 6;
		}
		// if main process wait to finish child process first 
		if (id != 0){
			wait(NULL); 
		}
		int i;
		for (i = n; i < n + 5; i++){
			printf("%d ", i);
			fflush(stdout);
		}
		if (id != 0){
			printf("\n"); 
		}
		return 0;
}
