

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char * argv[]){
	
	// Craete A FIFO (named Pipe) and check if already created
	if( mkfifo ("myfifo1",0777) == -1){
		if(errno != EEXIST){
			printf("Could not craete fifo file\n");
			return 1;
		}
	}
	int x = 97;
    //open file
	printf("openning..\n");
	int fd = open("myfifo1",O_RDWR);
	if (fd == -1){
		printf("Error in file openning\n");
		return 3;
	}
	printf("opened..\n");
	//Write
	if (write(fd,&x,sizeof(x)) == -1){
		printf("Error In file Writing\n");
		return 2;
	}
	printf("Written..\n");
	close(fd);
	printf("closed..\n");
	return 0;
}
