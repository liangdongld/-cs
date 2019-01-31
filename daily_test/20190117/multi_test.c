#include <stdio.h>
int multi(int a,int b);
int main(){
	srand(time(NULL));
	int a[2],i;
	for(i=0;i<2;i++){
		a[i]=rand()%100;
		printf("a[i]=%d  ",a[i]);
	}
	printf("\n");
	printf("%d",multi(a[0],a[1]));	
	printf("\n");
	return 0;
}
