#include <func.h>
int main(){
	int fp[2]={0};
	pipe(fp);//0为读管道 1为写管道
	pid_t pid=fork();
	char ch[128]={'0'};
	if(pid>0){//父进程
		close(fp[1]);//关闭写管道
		sleep(1);
		memset(ch,0,sizeof(ch));
		read(fp[0],ch,sizeof(ch));
		printf("%s\n",ch);
		exit(0);
	}else{//子进程
		close(fp[0]);
		memset(ch,0,sizeof(ch));
		write(fp[1],"hello",sizeof("hello"));
		wait(NULL);
		return 0;
	}
	return 0;
}
