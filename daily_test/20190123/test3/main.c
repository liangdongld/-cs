#include <func.h>
int main(){
	int shm=shmget(IPC_PRIVATE,1024,IPC_CREAT|0600);
	if(shm==-1){
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork()>0){//父进程
		char *p =(char*)shmat(shm,NULL,0);
		memset(p,0,1024);
		sprintf(p,"How are you?");
		wait(NULL);
		return 0;
	}else{
		sleep(1);
		char *p =(char*)shmat(shm,NULL,0);
		printf("%s\n",p);
		exit(0);
	}
	return 0;
}
