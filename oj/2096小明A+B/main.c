#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        a=a%100;
        b=b%100;
        int c=a+b;
        c=c%100;
        printf("%d\n",c); 
    } 
    return 0;
}

