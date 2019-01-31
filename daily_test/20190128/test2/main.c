//创建一个子线程，传入数值1，在子线程中能够获取并打印，子线程退出，返回数值2，主线程通过pthread_join获取等待子线程结束并获取子线程的退出值并打印
#include <func.h>
void *pfunc(void *i) {
	printf("%ld\n", (long)i);
	pthread_exit((void*)2);
}
int main() {
	pthread_t pid;
	pthread_create(&pid, NULL, pfunc, (void*)1);
	int i;
	pthread_join(pid, (void**)&i);
	printf("%d\n", i);
	return 0;
}
