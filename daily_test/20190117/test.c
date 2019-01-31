#include <stdio.h>
#include <stdlib.h>
#define N 20
void Qsort(int a[], int low, int high);
int main(){
	int a[N];
	int i;
	srand(time(NULL));	
	for(i=0;i<20;i++){
		a[i]=rand()%100;
		printf("%d ",a[i]);
	}
	printf("\n");
	Qsort(a,0,19);
	for(i=0;i<20;i++)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
