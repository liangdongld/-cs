#include <func.h>
typedef struct {
    int ret;
    pthread_mutex_t m;
}threadinfo;
void *sfunc1(void *p) {
    threadinfo *th = (threadinfo*)p;
    int *i=(int*)calloc(1,sizeof(int));
    while(1){
        pthread_mutex_lock(&th->m);//上锁
        if(th->ret>0){
            th-> ret--;
            (*i)++;
            pthread_mutex_unlock(&th->m);
        }else{
            pthread_mutex_unlock(&th->m);
            break;  
        }
    }

    pthread_exit((void*)i);
}
void *sfunc2(void *p) {
    threadinfo *th = (threadinfo*)p;
    int *i=(int*)calloc(1,sizeof(int));
    while(1){
        pthread_mutex_lock(&th->m);//上锁
        if(th->ret>0){
            th-> ret--;
            (*i)++;
            pthread_mutex_unlock(&th->m);
        }else{
            pthread_mutex_unlock(&th->m);
            break;  
        }
    }
    pthread_exit(i);
}
int main() {
    threadinfo th;
    th.ret = 20000000;
    pthread_mutex_init(&th.m, NULL);//初始化互斥锁
    pthread_t p1, p2;
    pthread_create(&p1, NULL,sfunc1, (void*)&th);
    pthread_create(&p2, NULL, sfunc2, (void*)&th);
    int *a,*b;
    pthread_join(p1,(void**)&a);
    pthread_join(p2,(void**)&b);
    printf("first thread:%d\nsecond thread:%d\n",*a,*b);
    return 0;
}
