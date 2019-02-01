#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete(char *a, char key) {
	char *start1, *start2;
	start1 = a;
	start2 = a;
	int count = 0;
	while(*start2!=NULL){
		if (*start2 == key) { 
			count++;
			start2++; 
		}
		else {
			*start1 = *start2;
			start1++;
			start2++;
		}
	}
	*(a + strlen(a)- count ) = '\0';
}
int main() {
	char a[100];
	char key;
	while (printf("Please input a string:\n"), gets(a) != NULL) {
		printf("Which letter do you want to delete ? :  ");
		scanf("%c", &key);
		delete(a, key);
		puts(a);
		printf("\n");
		rewind(stdin);
	}
}