#include <func.h>
void getT(){
    time_t now=time(NULL);
    struct tm *th=gmtime(&now);
    if((th->tm_hour+8)>24){
        th->tm_hour-=24;
        th->tm_mday++;
    }
    printf("%d-%02d-%02d %02d:%02d:%02d\n",th->tm_year+1900,th->tm_mon+1,th->tm_mday,th->tm_hour+8,th->tm_min,th->tm_sec);
}
void *tfunc(void *p){
    sleep(5);
    getT();
}
int main()
{
    pthread_t tpid;
    pthread_create(&tpid,NULL,tfunc,NULL);
    sleep(2);
    getT();
    pthread_join(tpid,NULL);
    return 0;
}

