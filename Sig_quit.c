#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void oh(int sig)
{
	printf("Pressed Ctrl+C\n");
    signal(SIGINT,oh);
}
int main(){
	signal(SIGQUIT,oh);
	while(1)
    {
		printf("Hello World!\n");
		sleep(1);
	}
}