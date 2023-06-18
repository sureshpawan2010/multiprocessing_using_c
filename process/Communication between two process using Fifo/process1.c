

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>


int main(int argc, char * argv[]){
	int arr[5];
	// Craete A FIFO (named Pipe) and check if already created
	if( mkfifo ("myfifo",0777) == -1){
		if(errno != EEXIST){
			printf("Could not create fifo file\n");
			return 1;
		}
	}

	int fd = open("myfifo",O_RDWR);
	if (fd == -1){
		printf("Error in file openning\n");
		return 3;
	}
	//fill arry with random numbers
	int i;
	srand(time(NULL));
	for( i = 0; i < 5; i++){
		arr[i]= rand() % 100;
	}
	for (i =0 ; i < 5; i++){
		printf("Write =%d\n",arr[i]);
		//Write Generated No
		if (write(fd,&arr[i],sizeof(int)) == -1){
			printf("Error In file Writing =%d\n",i);
			return 2;
		}
	}
	close(fd);
	return 0;
}
