#include "func.h"
void printdir(char *dirname,char *filename){
	DIR *pdir;
	pdir=opendir(dirname);
	if(NULL==pdir){
		perror("opendir");
		return;
	}
	struct dirent *p;
	char path[512]={0};
	while((p=readdir(pdir))!=NULL){
		if(!strcmp(p->d_name,".")||!strcmp(p->d_name,".."))continue;
		if(!strcmp(p->d_name,filename)){
			printf("Find file directory:%s/%s\n",dirname,filename);
		}
		if(p->d_type==4){//如果为目录文件，则进入搜索
			sprintf(path,"%s%s%s",dirname,"/",p->d_name);
			printdir(path,filename);
		}
	}
	closedir(pdir);
}

int main(int argc,char **argv){
	args_check(argc,3);
	printdir(argv[1],argv[2]);
	return 0;
}
