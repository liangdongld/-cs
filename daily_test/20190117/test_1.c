#include <stdio.h>
#define N 20
int main(){
	int a[N],i;
	srand(time(NULL));
	for(i=0;i<N;i++){
		a[i]=rand()%100;
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
