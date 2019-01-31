#include "func.h"
int main(int argc,char **argv){
	args_check(argc,2);
	int fp=open(argv[1],O_RDWR);
	if(-1==fp){
		perror("open");
		return -1;
	}
	printf("uid : %d gid : %d\n", getuid(), getgid());
	printf("eudi: %d egid: %d\n", geteuid(), getegid());
	write(fp,"Hello",6);
	close(fp);
	return 0;
}
