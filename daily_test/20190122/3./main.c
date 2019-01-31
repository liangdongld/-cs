#include "func.h"
int main(){
	pid_t pid=fork();
	if(0==pid){
		printf("child\n");
		return 0;
	}else{
		printf("Father\n");
		wait(NULL);
		while(1);
	}
}
