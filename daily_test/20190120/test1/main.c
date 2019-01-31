#include "func.h"
typedef struct student{
	int id;
	char name[20];
	int score;
	
}student;
int main(int argc,char **argv){
	int fp=open(argv[1],O_RDWR);
	char buf[512]={0};
	student *p=(student*)calloc(3,sizeof(student));
	int i,ret;
	for(i=0;i<3;i++){
		memset(buf,0,sizeof(buf));
		scanf("%d %s %d",&((p+i)->id),(p+i)->name,&((p+i)->score));
		sprintf(buf,"%d %s %d\n",((p+i)->id),(p+i)->name,((p+i)->score));
		ret=write(fp,buf,sizeof(buf));
	}
	if(ret==-1){
		printf("error");
		return -1;
	}
	lseek(fp,0,SEEK_SET);
	while((ret=read(fp,buf,sizeof(buf)))>0){
		printf("%s",buf);
	}
	close(fp);
	return 0;
}
