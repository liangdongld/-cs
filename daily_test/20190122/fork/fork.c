#include "func.h"
void p(int *i){
	while(*i>0);
	if(*i>0)*i--;
}
void v(int *i){
	*i++;
}
int main(){
	int empty=5,full=0;
	pid_t a=fork();
	if(0==a){
		p(&empty);
		v(&full);
		printf("product a good\n");
	}//else{
	//	p(&full);
	//	v(&empty);
	//	printf("use a good\n");
//	}
}
