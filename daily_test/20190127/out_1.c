#include <func.h>
int main(int argc, char **argv) {
	args_check(argc, 2);
	int shmid = shmget((key_t)1000, 1024, IPC_CREAT | 0600);//打开共享内存
	if (-1 == shmid) {
		perror("shmeget");
	}
	if (fork() > 0) {//读取自己窗口所发消息
		char *buf = (char*)shmat(shmid, NULL, 0);
		while (1) {
			if (buf[0] != 0) {
				printf("%s\n", buf);
				memset(buf, 0, sizeof(buf));
			}
		}
	}
	else {//读取对方窗口所发消息
		int fp_r = open(argv[2], O_RDONLY);
		char buf[1024];
		while (1) {
			memset(buf, 0, sizeof(buf));
			read(fp_r, buf, sizeof(buf));
			printf("%60s\n", buf);
		}
	}

	return 0;
}