#include "func.h"
int main(int argc,char **argv){
	args_check(3,argc);	
	int fp1=open(argv[1],O_RDONLY);
	if(-1==fp1){
		perror("open");
		return -1;
	}
	int fp2=open(argv[2],O_WRONLY);
	if(-1==fp2){
		perror("open1");
		return -1;
	}
	char buf[128]={0};
	int ret;
	fd_set rdset;
	while(1){
		//因为rdset是传入传出参数，每次执行后 rdset里边剩下 STDIN_FILENO或者fp1，所以需要每次都要加入	
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(fp1,&rdset);
		ret=select(fp1+1,&rdset,NULL,NULL,NULL);
		if(ret>0){
			if(FD_ISSET(STDIN_FILENO,&rdset)){
				memset(buf,0,sizeof(buf));
				read(STDIN_FILENO,buf,sizeof(buf));
				write(fp2,buf,strlen(buf)-1);
			}
			if(FD_ISSET(fp1,&rdset)){
				memset(buf,0,sizeof(buf));
				read(fp1,buf,sizeof(buf));
				if(strlen(buf)==0)break;
				printf("chat1: %s\n",buf);
			}
		}
	}
	return 0;
}
