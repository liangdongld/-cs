//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char* licenseKeyFormatting(char* S, int K) {
//	int len = strlen(S);
//	int i, count = 0, count2 = 0;
//	char *a = (char*)calloc(len, sizeof(char));
//	for (i = 0; i < len; i++) {
//		if (S[i] != '-') {
//			a[count] = S[i];
//			count++;
//		}
//	}
//	int num = count%K;
//	if (num != 0) {
//		for (i = 0; i < num; i++)S[i] = a[i];
//		S[num] = '-';
//	}
//	for (i = num == 0 ? 0 : num + 1; i < count; i++) {
//		if (count2 % (K + 1) != 0 || count2 == 0) {
//			S[count2] = a[i];
//		}
//		else {
//			S[count2] = '-';
//			i--;
//		}
//		count2++;
//	}
//	return S;
//}
//
//int main() {
//	char *S = (char*)calloc(128, sizeof(char));
//	strcpy(S, "5F3Z-2e-9-w");
//	S = licenseKeyFormatting(S, 4);
//	printf("%s\n", S);
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[] = "Hello";
	printf("%d\n", sizeof(a));
	return 0;

}