#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
void *thread_function(void *arg);
char message[]="ArgumentCommand";
int main(){
        int res;
        pthread_t a_thread;
        void *thread_result;
        res=pthread_create(&a_thread,NULL,thread_function,(void*)message);
        if(res!=0){
                perror("Thread Creation Failed\n");
                exit(EXIT_FAILURE);
        }
        printf("Waiting for thread to execute..\n");
        res=pthread_join(a_thread,&thread_result);
        if(res!=0){
        perror("Thread join failed\n");
                exit(EXIT_FAILURE);
        }
        printf("After joined, %s\n",(char*)thread_result);
printf("Posix Implemented Successfully %s\n",message);
        exit(EXIT_SUCCESS);
}
void *thread_function(void *arg){
        printf("Thread function is executing, argument uses %s\n",(char*)arg);
        sleep(3);
        strcpy(message,"!\n");
        pthread_exit("Returned Command\n");
}
