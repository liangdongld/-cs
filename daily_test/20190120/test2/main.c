#include "func.h"
int main(int argc,char **argv){
	int fp1=open(argv[1],O_RDWR);	
	int fp2=open(argv[2],O_RDWR);
	char buf[6];
	fflush(stdout);
	int ret=read(STDIN_FILENO,buf,sizeof(buf));
	printf("%d\n",ret);
	buf[ret]='\0';
	printf("%s\n",buf);
	write(fp1,buf,sizeof(buf));
	fflush(stdout);
	ret=read(STDERR_FILENO,buf,sizeof(buf));	
	buf[ret]='\0';
	printf("%d\n",ret);
	write(fp2,buf,sizeof(buf));
	return 0;
}
