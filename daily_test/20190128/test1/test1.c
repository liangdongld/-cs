#include <func.h>

void sigfun(int num) {
	time_t now;
	now = time(NULL);
	printf("%s", ctime(&now));
}
int main() {
	signal(SIGVTALRM, sigfun);
	struct timeval start, jmp;
	start.tv_sec = 1;
	start.tv_usec = 0;
	jmp.tv_sec = 1;
	jmp.tv_usec = 0;
	struct itimerval ti;
	ti.it_value = start;
	ti.it_interval = jmp;
	setitimer(ITIMER_VIRTUAL, &ti, NULL);
	sleep(3);
	while (1);
}