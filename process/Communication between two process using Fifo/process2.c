

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
	int fd = open("myfifo",O_RDWR);
	if (fd == -1){
		printf("Error in file openning\n");
		return 3;
	}
	printf("opend\n");
	//fill arry with random numbers
	int i;
	for (i =0 ; i < 5; i++){
		//Write Generated No
		if (read(fd,&arr[i],sizeof(int)) == -1){
			printf("Error In file Writing =%d\n",i);
			return 2;
		}
		printf("Received %d\n",arr[i]);
	}
	printf("Read Done\n");
	close(fd);
	return 0;
}
