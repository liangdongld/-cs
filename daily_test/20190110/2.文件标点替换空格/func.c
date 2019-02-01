#include "func.h"
void change(char *a) {

	if (*a >= 'a'&&*a <= 'z' || *a >= 'A'&&*a <= 'Z'||*a=='\n'||*a>='0'&&*a<='9')return;
	else *a = ' ';
	return;
}