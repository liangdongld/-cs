//»ð³µÊÛÆ±
#include <func.h>
typedef struct {
	pthread_mutex_t thmutex;
	pthread_cond_t thcond;
	int ticket;
}thData;
void *sfunc1(void *p) {
	thData *th = (thData*)p;
	while (1) {
		pthread_mutex_lock(&th->thmutex);
		if (th->ticket > 0) {
			printf("W1,Now:%d\n", th->ticket);
			th->ticket--;
			if (th->ticket == 0)pthread_cond_signal(&th->thcond);
			printf("Window 1, %d  now\n", th->ticket);
			pthread_mutex_unlock(&th->thmutex);
		}
		else {
			pthread_mutex_unlock(&th->thmutex);
			break;
		}
		sleep(1);
	}
}
void *sfunc2(void *p) {
	thData *th = (thData*)p;
	while (1) {
		pthread_mutex_lock(&th->thmutex);
		if (th->ticket > 0) {
			printf("W2,Now:%d\n", th->ticket);
			th->ticket--;
			if (th->ticket == 0)pthread_cond_signal(&th->thcond);
			printf("Window 2, %d  now\n", th->ticket);
			pthread_mutex_unlock(&th->thmutex);
		}
		else {
			pthread_mutex_unlock(&th->thmutex);
			break;
		}
		sleep(1);
	}
}
void *sfunc3(void *p) {
	thData *th = (thData*)p;
	pthread_mutex_lock(&th->thmutex);
	pthread_cond_wait(&th->thcond, &th->thmutex);
	printf("Adding ticket....\n");
	th->ticket = 10;
	sleep(3);
	printf("Now ticket = %d\n", th->ticket);
	sleep(2);
	pthread_mutex_unlock(&th->thmutex);
	pthread_exit(NULL);
}
int main() {
	thData ticketInfo;
	int ret;
	ret = pthread_mutex_init(&ticketInfo.thmutex, NULL);
	if (0 != ret) {
		printf("pthread_mutex_init failed,ret=%d", ret);
		return -1;
	}
	ret = pthread_cond_init(&ticketInfo.thcond, NULL);
	if (0 != ret) {
		printf("pthread_cond_init failed,ret=%d", ret);
		return -1;
	}
	ticketInfo.ticket = 20;
	pthread_t p1, p2, p3;
	pthread_create(&p1, NULL, sfunc1, (void*)&ticketInfo);
	pthread_create(&p2, NULL, sfunc2, (void*)&ticketInfo);
	pthread_create(&p3, NULL, sfunc3, (void*)&ticketInfo);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	return 0;
}