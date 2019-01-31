//1、signal设置信号处理行为，演示不同信号到来时，后来的信号会打断原有信号的信号处理函数效果
#include <func.h>
void Sfunc(int num, siginfo_t *pSignInfo, void *pReserved) {
	int i;
	for (i = 3; i > 0; i++) {
		printf("%d is coming :%d\n", num, i);
		sleep(1);
	}
	printf("%d is over\n", num);
}
int main() {
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_sigaction = Sfunc;
	act.sa_flags = SA_SIGINFO;
	int ret=sigaction(SIGINT, &act, NULL);
	if (ret == -1) {
		perror("sigaction");
		return -1;
	}
	while (1);
	return 0;
}
