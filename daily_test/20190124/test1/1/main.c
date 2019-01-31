#include <func.h>
int main() {
	int i;
	int semArr = semget(1000, 1, IPC_CREAT | 0600);
	if (-1 == semArr) {
		perror("semget");
	}
	int sem = semctl(semArr, 0, SETVAL, 1);//��һ������Ϊ�����ź������صı�ʶ�����ڶ���������ʾ�ź����ӵڼ�����ʼ����������ʾ�Ը��ź�������ָ����ĸ� ���������ΪSETVAL�����ĸ�����Ϊ�ź����ĳ�ֵ
	int ret = shmget(1000, 4096, IPC_CREAT | 0600);
	int *p = (int*)shmat(ret, NULL, 0);
	if (-1 == ret) {
		perror("shmget");
	}
	struct sembuf sopp, sopv;
	sopp.sem_op = -1;
	sopp.sem_num = 0;
	sopp.sem_flg = SEM_UNDO;
	sopv.sem_num = 0;
	sopv.sem_op = 1;
	sopv.sem_flg = SEM_UNDO;
	p[0] = 0;
	if (fork() > 0) {//������
		for (i = 0; i < 10000000; i++) {
			semop(semArr, &sopp, 1);
			p[0]=p[0]+1;
			semop(semArr, &sopv, 1);
		}
		wait(NULL);
		printf("%d\n", p[0]);
        exit(0);
	}
	else {
		for (i = 0; i < 100000000; i++) {
			semop(semArr, &sopp, 1);
			p[0]=p[0]+1;
			semop(semArr, &sopv, 1);
		}
		exit(0);
	}
	semop(ret, &sopp, 1);
	return 0;
}
