//����2�ŵ��źŴ�����Ϊ����2�ŵ���ʱ����ӡ�ź�����
#include <func.h>
void signal_2(int a) {
	printf("before sleep signal %d is coming!\n", a);
	sleep(2);
	printf("after sleep signal %d is coming!\n", a);
}
int main()
{
	signal(SIGINT, signal_2);
	signal(SIGQUIT, signal_2);
	printf("hello World\n");
	while (1);
    return 0;
}