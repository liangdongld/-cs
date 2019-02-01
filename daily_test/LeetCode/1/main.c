#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isHappy(int n) {
	static int q = 0;
	int count = 0, i, sum = 0;
	int a[10] = { 0 };
	while (n) {
		a[count] = n % 10;
		n /= 10;
		count++; 
	}
	for (i = 0; i < count; i++) {
		sum += a[i] * a[i];
	}
	if (sum == 1)return true;
	else {
		if (sum == n)return false;
		isHappy(sum);
	}
}
int main() {
	bool i = isHappy(2);

	return 0;
}