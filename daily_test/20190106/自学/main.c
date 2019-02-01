#include <stdio.h>
typedef int(*pFunc) (int, int);//定义函数指针 pFunc  返回值为int类型  传入参数为两个int类型
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a*b;
}
int divide(int a, int b) {
	return a / b;
}
int main() {
	int a, b;
	char c;
	pFunc p1 = NULL;
	scanf("%d%c%d", &a, &c, &b);
	rewind(stdin);
	switch (c)
	{
	case '+':p1 = add; break;
	case '-':p1 = sub; break;
	case '*':p1 = multiply; break;
	case '/':p1 = divide; break;
	default:
		printf("input error!");
		break;
	}
	printf("%d %c %d = %d\n", a, c, b, p1(a, b));
	return 0;
}