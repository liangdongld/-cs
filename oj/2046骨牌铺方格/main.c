//AC
#include <stdio.h>
long long calculate(int n){

    int i;
    long long ppre=1,pre=1,cur;
    if(n==1){
        cur =1;
        return cur;
    }
    for(i=2;i<=n;i++){
        cur=ppre+pre;
        ppre=pre;
        pre=cur;
    }
    return cur;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",calculate(n));
    }
    return 0;
}
