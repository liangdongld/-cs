#include<func.h>
int main(int argc, char **argv) {
	args_check(argc, 2);
	int shmid = shmget((key_t)2000, 1024, IPC_CREAT | 0600);//���������ڴ�
	if (-1 == shmid) {
		perror("shmeget");
	}
	if (fork() > 0) {//���͸��Լ��Ĵ���
		char *buf = (char*)shmat(shmid, NULL, 0);
		memset(buf, 0, sizeof(buf));
		while (1) {
			scanf("%s", buf);
		}
	}
	else {//���͸��Է�����
		int fp_w = open(argv[2], O_WRONLY);//ֻд�򿪹ܵ�
		char *buf = (char*)shmat(shmid, NULL, 0);
		while (1) {
			while (buf[0] == 0);
			write(fp_w, buf, sizeof(buf));
		}
	}
	//shmctl(shmid, IPC_RMID, NULL);//ɾ�������ڴ�
	return 0;
}