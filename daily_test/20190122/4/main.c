#include "func.h"
void deamon(){
	if(fork()>0){
		exit(1);
	}
	setsid();
	chdir("/");
	umask(0);
	int i=0;
	for(i=0;i<3;i++){
		close(i);
	}
} 
int main(){
	deamon();
	int fp=open("/tmp/log",O_RDWR);
	while(1){
		sleep(1);
		write(fp,"I have sleep 1s\n",sizeof("I have sleep 1s"));
	}
}
