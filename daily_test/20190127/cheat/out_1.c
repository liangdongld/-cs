#include <func.h>
int main(int argc, char **argv) {
    args_check(argc, 2);
    int shmid = shmget(2100, 4096, IPC_CREAT | 0600);//打开共享内存
    if (-1 == shmid) {
        perror("shmeget");
    }
    int semid = semget((key_t)1500, 2, IPC_CREAT | 0600);
    if (-1 == semid) {
        perror("semget");
    }

    struct sembuf sop1p;
    if (fork() > 0) {//读取自己窗口所发消息
        sop1p.sem_num = 0;
        sop1p.sem_flg = SEM_UNDO;
        sop1p.sem_op = -1;
        char *buf = (char*)shmat(shmid, NULL, 0);
        while (1) {
            semop(semid,&sop1p,1);
            printf("%s",buf);
            memset(buf, 0, 4096);
        }
    }
    else {//读取对方窗口所发消息
        int fp_r = open(argv[1], O_RDONLY);
        char buf[4096];
        memset(buf, 0, sizeof(buf));
        while (1) {
            read(fp_r, buf, 4096);
            printf("%60s",buf);
            memset(buf, 0,4096);
        }
    }
    return 0;
}
