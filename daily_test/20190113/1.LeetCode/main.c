#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	if (len == 0)return 0;
	int i, j, start = 0, count = 0, max = 0;
	for (i = 1; i < len; i++) {
		count = 0;
		for (j = start; j < i; j++) {
			if (s[j] != s[i]) {
				count++;
				if (count > max)max = count;
			}
			else {;
				count = 0;
				start = j+1;
				break;
			}
		}
	}
	return max+1;
}