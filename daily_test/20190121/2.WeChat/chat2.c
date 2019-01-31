#include "func.h"
int main(int argc,char **argv){
	args_check(3,argc);	
	int fp1=open(argv[1],O_WRONLY);
	if(-1==fp1){
		perror("open");
		return -1;
	}
	int fp2=open(argv[2],O_RDONLY);
	if(-1==fp2){
		perror("open1");
		return -1;
	}
	char buf[128]={0};
	int ret;
	fd_set rdset;
	while(1){
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(fp2,&rdset);
		ret=select(fp2+1,&rdset,NULL,NULL,NULL);
		if(ret>0){
			if(FD_ISSET(STDIN_FILENO,&rdset)){
				memset(buf,0,sizeof(buf));
				read(STDIN_FILENO,buf,sizeof(buf));
				write(fp1,buf,strlen(buf)-1);
			}
			if(FD_ISSET(fp2,&rdset)){
				memset(buf,0,sizeof(buf));
				read(fp2,buf,sizeof(buf));
				if(strlen(buf)==0)break;
				printf("chat2: %s\n",buf);
			}
		}
	}
	return 0;
}
