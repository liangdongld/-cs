#include <stdio.h>
#include <stdlib.h>
int  main() {
	FILE *fp;
	char buf[128] = "thank you very much";
	fp = fopen("liangdong.txt", "r+");
	if (NULL == fp) {
		perror("fopen");
		goto end;
	}
	int ret = fwrite(buf, sizeof(char), sizeof(buf), fp);
	
	fclose(fp);
end:
	system("pause");
}