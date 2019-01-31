//AC
#include <stdio.h>
#include <stdlib.h>
int main() 
{
	int n;
	int a[100];
	while (scanf("%d", &n) != EOF) {
		int i;
		int max = 0;
		int flag=1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] > max)
			{
				max = a[i];
			}

		}
		while (1) {
			for (i = 0; i < n; i++) {
				if (max%a[i] == 0)
				{
					flag = 1;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag)break;
			max++;
		}
		printf("%d\n", max);
	}
	return 0;
}
