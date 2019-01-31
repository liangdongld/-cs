#include<func.h>
int main(int argc, char **argv) {
	args_check(argc, 2);
	int shmid = shmget(2000, 4096,0600 |IPC_CREAT);//创建共享内存
	if (-1 == shmid) {
		perror("shmeget");
	}
	char *buf; 
    buf= (char*)shmat(shmid, NULL, 0);
	memset(buf, 0, 4096);
	char *tmp = (char*)calloc(4096, sizeof(char));

	int semid = semget((key_t)1600, 2, IPC_CREAT | 0600);
	if (-1 == semid) {
		perror("semget");
	}
	unsigned short arr[2] = { 0,0 };
	semctl(semid, 0, SETALL, arr);
	struct sembuf sop1v;
	sop1v.sem_op = 1;
	sop1v.sem_num = 0;
	sop1v.sem_flg= SEM_UNDO;
	while (1) {
		read(STDIN_FILENO, tmp,4096);
		memcpy(buf, tmp, 4096);
		semop(semid, &sop1v, 1);
		int fp_w = open(argv[1], O_WRONLY);
		write(fp_w, tmp, 4096);
		memset(tmp, 0, 4096);
	}
}
