#include "func.h"
int main() {
	FILE *in, *out;
	char ch;
	in = fopen("The_Holy_Bible.txt", "r+");
	out = fopen("back.txt", "r+");
	if (NULL == in||NULL==out) {
		perror("fopen");
		goto end;
	}
	while (!feof(in)) {
		ch = fgetc(in);
		change(&ch);
		fputc(ch, out);
	}
	fclose(in);
	fclose(out);
	unlink("The_Holy_Bible.txt");
	rename("back.txt", "The_Holy_Bible.txt");
end:
	system("pause");
	return 0;
}