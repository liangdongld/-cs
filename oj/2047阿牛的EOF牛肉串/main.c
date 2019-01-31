//递推公式 a[n]=2*a[n-1]+2*a[n-2];
//AC
#include <stdio.h>
#include <stdlib.h>
long long calculate(int n){
    long long *ret=(long long*)calloc(51,sizeof(long long)); 
    ret[1]=3;ret[2]=8;ret[3]=22; 
    int i;
    for(i=4;i<=n;i++){
        ret[i]=ret[i-1]*2+ret[i-2]*2; 
    }
    return ret[n];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",calculate(n));
    }
    return 0;
}
