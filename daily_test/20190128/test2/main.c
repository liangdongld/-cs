//����һ�����̣߳�������ֵ1�������߳����ܹ���ȡ����ӡ�����߳��˳���������ֵ2�����߳�ͨ��pthread_join��ȡ�ȴ����߳̽�������ȡ���̵߳��˳�ֵ����ӡ
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
