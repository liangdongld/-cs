#include <func.h>

void init() {
	int shm_pid = shmget(1000, 6 * sizeof(int), IPC_CREAT | 0600);
	int *p = (int*)shmat(shm_pid, NULL, 0);
	p[3] = getpid();
}
void killfunc(int num) {
	int shm_pid = shmget(1000, 6 * sizeof(int), IPC_CREAT | 0600);
	int shmid = shmget((key_t)2000, 4096, IPC_CREAT | 0600);//打开共享内存
	int shmid_1 = shmget(2100, 4096, 0600 | IPC_CREAT);//创建共享内存
	int semid = semget((key_t)1500, 2, IPC_CREAT | 0600);
	int *p = (int*)shmat(shm_pid, NULL, 0);
	int i;
	kill(p[4], SIGQUIT);
	kill(p[5], SIGQUIT);
	for (i = 0; i < 4; i++) {
		if (i == 3)continue;
		kill(p[i], SIGQUIT);
	}
	semctl(semid, 0, IPC_RMID);
	shmctl(shm_pid, IPC_RMID, NULL);
	shmctl(shmid_1, IPC_RMID, NULL);
	shmctl(shmid, IPC_RMID, NULL);
	kill(p[3], SIGQUIT);
}
int main(int argc, char **argv) {
	init();
	signal(SIGINT, killfunc);
	args_check(argc, 2);
	int shmid = shmget((key_t)2000, 4096, IPC_CREAT | 0600);//打开共享内存
	int semid = semget((key_t)1500, 2, IPC_CREAT | 0600);
	if (-1 == semid) {
		perror("semget");
	}
	struct sembuf sop1p;
	if (fork() > 0) {//读取自己窗口所发消息
		sop1p.sem_num = 1;
		sop1p.sem_flg = SEM_UNDO;
		sop1p.sem_op = -1;
		char *buf = (char*)shmat(shmid, NULL, 0);
		while (1) {
			semop(semid, &sop1p, 1);
			printf("%s", buf);
			memset(buf, 0, 4096);
		}
	}
	else {//读取对方窗口所发消息
		int shm_pid = shmget(1000, 6 * sizeof(int), IPC_CREAT | 0600);
		int *p = (int*)shmat(shm_pid, NULL, 0);
		p[4] = getpid();
		int fp_r = open(argv[1], O_RDONLY);
		char buf[4096];
		memset(buf, 0, sizeof(buf));
		while (1) {
			read(fp_r, buf, 4096);
			printf("%60s", buf);
			memset(buf, 0, 4096);
		}
	}
	return 0;
}

