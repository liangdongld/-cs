//AC
#include <stdio.h>
#include<memory.h>
void calculate(int a,int b){
    a=a*100;
    int i;
    int ret[20],count=0;
    memset(ret,0,20*sizeof(int));
    for(i=0;i<100;i++){
        if((a+i)%b==0){
            ret[count]=i;
            count++;
        }
    }
    for(i=0;i<count;i++)printf(i==0?"%02d":" %02d",ret[i]);
}
int main()
{
    int a,b;
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)return 0;
        calculate(a,b);
        printf("\n"); 
    }
    return 0;
}

