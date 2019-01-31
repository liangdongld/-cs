#include "func.h"

int main(int argc,char** argv)
{
	args_check(argc,3);
	int fdr=open(argv[1],O_RDONLY);//以读的方式打开一号管道
	if(-1==fdr)
	{
		perror("open");
		return -1;
	}
	int fdw=open(argv[2],O_WRONLY);//以写的方式打开二号管道
	if(-1==fdw)
	{
		perror("open1");
		return -1;
	}
	printf("I am chat1\n");
	char buf[128]={0};
	int ret;
	fd_set rdset;//描述符监控的读集合
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(STDIN_FILENO,&rdset))
			{
				memset(buf,0,sizeof(buf));
				read(STDIN_FILENO,buf,sizeof(buf));//读取标准输入
				write(fdw,buf,strlen(buf)-1);//写端管道内
			}
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				printf("%s\n",buf);
			}
		}
	}
	return 0;
}
