#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	printf("pid=%d\tppid=%d\n",getpid(),getppid());
	return 0;
}
