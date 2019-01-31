#include <func.h>
#include <stdbool.h>
int main(){
	int shm=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0600);
	if(shm==-1){
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}
	int shbool=shmget(IPC_PRIVATE,sizeof(bool),IPC_CREAT|0600);
	if(shbool==-1){
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork()>0){
			int *p=(int*)shmat(shm,NULL,0);
			memset(p,0,sizeof(int ));
			int i;
			bool *q=(bool*)shmat(shbool,NULL,0);
			*q=true;
			for(i=0;i<10000000;i++){
				while(*q==false);
				*p+=1;
				*q=false;
			}
			wait(NULL);
			printf("%d\n",*p);
			return 0;
		}else{
			int *p=(int*)shmat(shm,NULL,0);
			int i;
			bool *q=(bool*)shmat(shbool,NULL,0);
			*p=true;
			for(i=0;i<10000000;i++){
				while(*q==true);
				*p+=1;
				*q=true;
			}
			exit(0);
		}
		return 0;
}
