#include<func.h>
int main(int argc, char **argv) {
	args_check(argc, 2);
	int shmid = shmget((key_t)1000, 1024, IPC_CREAT | 0600);//创建共享内存
	if (-1 == shmid) {
		perror("shmeget");
	}
	if (fork()>0) {//发送给自己的窗口
		char *buf = (char*)shmat(shmid, NULL, 0);
		memset(buf, 0, sizeof(buf));
		while (1) {
			scanf("%s", buf);
		}
	}
	else {//发送给对方窗口
		int fp_w = open(argv[1], O_WRONLY);//只写打开管道
		char *buf = (char*)shmat(shmid, NULL, 0);
		while (1) {
			while (buf[0] == 0);
			write(fp_w, buf, sizeof(buf));
		}
	}
	//shmctl(shmid, IPC_RMID, NULL);//删除共享内存
	return 0;
}