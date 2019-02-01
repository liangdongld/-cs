#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int replace(char *a) {
	int count = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (*(a + i) == ' ')count++;
	}
	int c = 0;
	for (int i = strlen(a); i >=0; i--) {
		if (a[i] != ' ')
			a[i+3*count-3*c] = a[i];
		else {
			a[i + 3 * count - 3 * c] = '0';
			a[i + 3 * count - 3 * c - 1] = '2';
			a[i + 3 * count - 3 * c - 2] = '0';
			a[i + 3 * count - 3 * c - 3] = '%';
			c++;
		}
	}

}

int main() {
	char a[100];
	while (gets(a) != NULL) {
		replace(a);
		puts(a);
	}
}