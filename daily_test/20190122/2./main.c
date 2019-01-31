#include "func.h"
int main(){
	pid_t pid=fork();
	if(0==pid){
		printf("I am child\n");
		while(1);
	}else{
		printf("I am father\n");
		while(1);
	}
	return 0;
}
