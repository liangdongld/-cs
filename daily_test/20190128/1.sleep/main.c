#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *thread_func(void * a) {
    int key = *(int*)a;
    usleep(key * 500);
    printf("%d ", key);
}
int main() {
    int a[10];
    int i;
    srand(time(NULL));
    printf("原数据:");
    for(i=0;i<10;i++){
        a[i]=rand()%100;
        printf(i==9?"%d\n":"%d ",a[i]);
    }
    pthread_t pid[10];
    printf("睡排后:");
    for (i = 0; i < 10; i++) {
        pthread_create(&pid[i], NULL, thread_func,&a[i]);
    }
    for (i = 0; i < 10; i++) {
        pthread_join(pid[i], NULL);
    }
    printf("\n");
    return 0;
}
