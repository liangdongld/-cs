//4、通过sigprocmask阻塞2号信号，睡眠5秒后，解除阻塞，2号信号得到执行；在睡眠后，解除阻塞之前，通过sigpending检测是否有信号挂起
#include <func.h>

int main() {
	sigset_t sig;
	sigset_t a;
	sigemptyset(&sig);
	sigaddset(&sig, SIGINT);
	sigprocmask(SIG_BLOCK, &sig, NULL);//全程阻塞2号信号
	sleep(2);
	sigpending(&a);
	if (sigismember(&a, SIGINT)) {
		printf("二号信号被挂起\n");
	}
	sigprocmask(SIG_UNBLOCK, &sig, NULL);
	return 0;
}
