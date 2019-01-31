#include "func.h"
int main(int argc,char **argv){
	char str[7]="hello\n";
	int fp=open(argv[1],O_RDWR);
	write(fp,str,sizeof(str));
	struct stat buf;
	fstat(fp,&buf);
	char *p=mmap(0,buf.st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fp,0);	
	if((char*)-1==p){
		perror("mmp");
		return -1;
	}
	strcpy(p,"World\n");
	munmap(p,buf.st_size);
	close(fp);
	return 0;
}
