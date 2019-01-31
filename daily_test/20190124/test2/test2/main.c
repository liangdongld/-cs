//生产者消费者进问题
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main() {
	int semArrid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0600);
	if (-1 == semArrid) {
		perror("semget");
		return -1;
	}
	unsigned short arr[2] = { 8,2 };//empty=8,full=2;
	semctl(semArrid, 0, SETALL, arr);
	struct sembuf sopp, sopv;
	if (fork() > 0) {//生产者进程
		sopp.sem_num = 0;
		sopp.sem_op = -1;
		sopp.sem_flg = SEM_UNDO;
		sopv.sem_num = 1;
		sopv.sem_op = 1;
		sopv.sem_flg = SEM_UNDO;
		while (1) {
			printf("I am producer. Now  empty=%d  full=%d\n", semctl(semArrid, 0, GETVAL) , semctl(semArrid, 1, GETVAL));
			semop(semArrid, &sopp, 1);//P(empty)
			printf("producting a good...\n");
			semop(semArrid, &sopv, 1);//V(full)
			printf("Now  empty=%d  full=%d\n", semctl(semArrid, 0, GETVAL), semctl(semArrid, 1, GETVAL));
			sleep(1);
		}
	}
	else {//消费者进程
		sopp.sem_num = 1;
		sopp.sem_op = -1;
		sopp.sem_flg = SEM_UNDO;
		sopv.sem_num = 0;
		sopv.sem_op = 1;
		sopv.sem_flg = SEM_UNDO;
		while (1) {
			printf("I am consumer. Now  empty=%d  full=%d\n", semctl(semArrid, 0, GETVAL) , semctl(semArrid, 1, GETVAL));
			semop(semArrid, &sopp, 1);//P(empty)
			printf("Using a good...\n");
			semop(semArrid, &sopv, 1);//V(full)
			printf("Now  empty=%d  full=%d\n", semctl(semArrid, 0, GETVAL), semctl(semArrid, 1, GETVAL));
			sleep(2);
		}
	}
	return 0;
}