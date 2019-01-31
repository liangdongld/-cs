#include <func.h>
typedef struct {
    int ret;
    pthread_mutex_t m;
}threadinfo;
void *sfunc1(void *p) {
    threadinfo *th = (threadinfo*)p;
    int i;
    for (i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&th->m);
        th->ret++;
        pthread_mutex_unlock(&th->m);
    }
}
void *sfunc2(void *p) {
    threadinfo *th = (threadinfo*)p;
    int i;
    for (i = 0; i < 10000000; i++) {
        pthread_mutex_lock(&th->m);
        th->ret++;
        pthread_mutex_unlock(&th->m);
    }
}
int main() {
    threadinfo th;
    th.ret = 0;
    pthread_mutex_init(&th.m, NULL);//初始化互斥锁
    pthread_t p1, p2;
    pthread_create(&p1, NULL,sfunc1, (void*)&th);
    pthread_create(&p2, NULL, sfunc2, (void*)&th);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("%d\n",th.ret);
    return 0;
}
