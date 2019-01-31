#include <stdio.h>
int main(){
	FILE *fp=fopen("file1.txt","rb+");
	char p[128];
	if(NULL==fp){
		perror("fopen");
	}
	fread(p,1,128,fp);
	printf("%s",p);
	fclose(fp);
	return 0;
}
