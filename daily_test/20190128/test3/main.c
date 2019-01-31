//3、创建子线程，主线程发送cancel，主线程回收子线程，并打印返回值
#include <func.h>
void *pfunc(void *i) {
	sleep(5);
	printf("I am child thread\n");
}
int main() {
	pthread_t pid;
	pthread_create(&pid, NULL, pfunc, NULL);
	printf("I am main thread\n");
	pthread_cancel(pid);
	int ret;
	pthread_join(pid, (void**)&ret);
	printf("ret=%d\n", ret);
}
