//AC
#include <stdio.h>
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		if (0 == a&&0 == b) break;
		int ret = 1, i;
		for (i = 0; i < b; i++) {
			ret *= a;
			if (ret > 1000)ret %= 1000;
		}
		printf("%d\n", ret);
	}
}