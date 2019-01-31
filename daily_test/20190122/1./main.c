#include "func.h"
int main(){
	pid_t pid=fork();
	if(0==pid){
		printf("Child PID is : %d \n",getpid());
		while(1);
	}else{
		printf("Father PID is : %d \n",getpid());
		while(1);
	}
	return 0;
}
