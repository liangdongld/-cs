//3、sigaction实现2号信号，屏蔽3号信号的执行效果，同时在2号信号的信号处理流程中，判断3号信号是否被挂起
#include <func.h>
void Sfunc(int num, siginfo_t *pSignInfo, void *pReserved) {
	printf("%d is coming\n", num);
	sleep(2);
}
int main() {
	struct sigaction act;
	int ret_1;
	memset(&act, 0, sizeof(act));
	act.sa_sigaction = Sfunc;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	int ret = sigaction(SIGINT, &act, NULL);
	if (ret == -1) {
		perror("sigaction");
		return -1;
	}
	while (1) {
		ret_1 = sigpending(SIGQUIT);
		if (ret_1&SIGQUIT == 1)printf("挂起\n");
	}
	return 0;
}