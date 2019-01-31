#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
	char a[128];
	getcwd(a,128);//获取当前目录
	printf("%s\n",a);
	chdir("..");//改变当前进程的目录	
	getcwd(a,128);//获取当前目录
	printf("%s\n",a);
	return 0;	
}
