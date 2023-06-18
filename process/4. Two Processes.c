

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <pthread.h>


int main(int argc, char * argv[]){
	  int arr[] = {1,2,3,4,1,2,4};
	  int fd[2];

	  if(pipe(fd) == -1){
		printf("Error in creating pipes\n");
	  }
	  int id = fork();
	  if(id == -1){
		printf("Erro In creating child process\n");
	  }
	  //child process
	  if(id == 0){
		int sum = 0;
		int i;
		for( i = 0; i < ((sizeof(arr)/sizeof(arr[0]))/2); i++ ){
			sum = sum+ arr[i];
		}
		close(fd[0]);
		// Write to File;
		write(fd[1],&sum,sizeof(int));
		close(fd[1]);
	  }else{
		int child_sum;
		//wait to finish child process
		//wait(NULL);
		close (fd[1]);
		read(fd[0],&child_sum,sizeof(int));
		close(fd[0]);
		printf("Sum Received From Child Process = %d\n",child_sum);

		//calculate sum on rem half array
		int sumy = 0;
		int j;
		for(j = ((sizeof(arr)/sizeof(arr[0]))/2); j < (sizeof(arr)/sizeof(arr[0])) ; j++){
			sumy += arr[j];	
		}
		printf("Sum from main process =%d\n",sumy);
		printf("Total sum of array = %d\n", (sumy+child_sum));
	  }

	return 0;
}
