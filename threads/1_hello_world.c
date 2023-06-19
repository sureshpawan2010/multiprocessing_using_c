#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /*For Working with POSIX threads*/
#include <unistd.h>  /*For pause() and sleep()*/

//function call back
static void * thread_fn_callback(void *arg){
    //Extract the passed argument in thead cration
    char *input =(char *)arg;
    //infinite loop
    while(1){
        printf("Input String =%s\n",input);
        //sleep for 1 seconds
        sleep(1);
    }
}

void thread1_create(void){
    //opaque object of threads //thead hndle
    pthread_t pthread1;
    /*
    *Take some arugmet to pass to the thread function.
    */
   static char *thread1_input = "I am thread no 1";
   /*
   * Return 0 on success, otherwise returns errorcodes,
   * all ptherads functions return -ve error code on failure 
   */
   int rc = pthread_create(&pthread1,
                            NULL,
                            thread_fn_callback,
                            (void *)thread1_input);
    if(rc != 0){
        printf("Error in thread1 creation\n");
    }
}

// Main thread
int main(int argc, char **argv){
    //create child thread
    thread1_create();
    printf("Main function/thread paused\n");
    //pause();
    while(1){
        printf("This is main thread\n");
        sleep(1);
    }
    return 0;
}