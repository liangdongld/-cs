//2、sigaction实现信号不断重入的执行效果
#include <func.h>
void Sfunc(int num){
	int i;
	for (i = 3; i > 0; i--) {
		printf("%d is coming :%d\n", num, i);
		sleep(1);
	}
	printf("%d is over\n", num);
}
int main() {
	signal(SIGINT, Sfunc);
	signal(SIGQUIT, Sfunc);
	while (1);
	return 0;
}