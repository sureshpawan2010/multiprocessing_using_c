#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /*For Working with POSIX threads*/
#include <unistd.h>  /*For pause() and sleep()*/

//function call back
static void * thread_fn_callback(void *arg){
    //Extract the passed argument in thead cration
    char *input =(char *)arg;
    int a = 0;
    //infinite loop
    while(a < 10){
        printf("Input String =%s\n",input);
        //sleep for 1 seconds
        sleep(1);
         if(a == 5)
             pthread_exit(0);
        a++;
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
    // Normal termination of main thread(i.e using return 0) of main thread will terminate all
    // child thread.
    // We can keep can keep alive our child thread even terminating our main thread by using 
    // pthread_exit(0) in main thread.
    pthread_exit(0);
    return 0;
}