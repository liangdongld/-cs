#include "func.h"
char *mode_print(int a){//转换进制
	char *ret=(char*)calloc(4,sizeof(char));
	if((a/4)!=0){
		ret[0]='r';
		a/=4;
	}else ret[0]='-';
	if((a/2)!=0){
		ret[1]='w';
		a/=2;
	}else ret[1]='-';
	if((a/1)!=0){
		ret[2]='x';
	}else ret[2]='-';
	return ret;
}
void printfile(char *filename){//打印每个文件信息
	struct stat buf;
	stat(filename,&buf);
	char mode_cur[20];
	//转化为八进制
	int all_mode=buf.st_mode&511;
	int usr_mode=all_mode&448;
	int group_mode=all_mode&56;
	int other_mode=all_mode&7;
	sprintf(mode_cur,"%s%s%s",mode_print(usr_mode),mode_print(group_mode),mode_print(other_mode));
	printf("%s %s %s %s %ld %ld %ld %s",mode_cur,\
	filename,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,\
	buf.st_size,buf.st_blksize,buf.st_blocks,ctime(&buf.st_mtime));
}
void travle_file(char *dirname){
	DIR *pdir;
	pdir=opendir(dirname);
	if(NULL==pdir){
		perror("opendir");
		return;
	}
	struct dirent *p;
	char path[512]={0};
	while((p=readdir(pdir))!=NULL){
		printfile(p->d_name);
	}
}
void getPath(){

    char pPath[256] = {0};
    getcwd(pPath,256);
    printf("filePath: %s\n", pPath);
}
int main(int argc,char **argv){
	if(argc != 2){
		return -1;
	}
	char dirname[20];
	//getPath();
	strcpy(dirname,argv[1]);	
	chdir(dirname);
	travle_file(dirname);
	//getPath();
	return 0;
}
