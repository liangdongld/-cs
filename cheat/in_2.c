#include<func.h>
void init() {
	int shm_pid = shmget(1000, 6 * sizeof(int), IPC_CREAT | 0600);
	int *p = (int*)shmat(shm_pid, NULL, 0);
	p[1] = getpid();

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
		if (i == 1)continue;
		kill(p[i], SIGQUIT);
	}
	semctl(semid, 0, IPC_RMID);
	shmctl(shm_pid, IPC_RMID, NULL);
	shmctl(shmid_1, IPC_RMID, NULL);
	shmctl(shmid, IPC_RMID, NULL);
	kill(p[1], SIGQUIT);
}
int main(int argc, char **argv) {
	init();
	signal(SIGINT, killfunc);
	args_check(argc, 2);
	int shmid = shmget(2000, 4096, 0600 | IPC_CREAT);//创建共享内存
	char *buf;
	buf = (char*)shmat(shmid, NULL, 0);
	memset(buf, 0, 4096);
	char *tmp = (char*)calloc(4096, sizeof(char));

	int semid = semget((key_t)1500, 2, IPC_CREAT | 0600);
	if (-1 == semid) {
		perror("semget");
	}
	unsigned short arr[2] = { 0,0 };
	semctl(semid, 0, SETALL, arr);
	struct sembuf sop1v;
	sop1v.sem_op = 1;
	sop1v.sem_num = 1;
	sop1v.sem_flg = SEM_UNDO;
	while (1) {
		read(STDIN_FILENO, tmp, 4096);
		memcpy(buf, tmp, 4096);
		semop(semid, &sop1v, 1);
		int fp_w = open(argv[1], O_WRONLY);
		write(fp_w, tmp, 4096);
		memset(tmp, 0, 4096);
	}
}

