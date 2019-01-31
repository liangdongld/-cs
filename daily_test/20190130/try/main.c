#include <func.h>

int main()
{
    char ip[]="192.168.0.101";
    struct in_addr myaddr;
    int iRet=inet_aton(ip,&myaddr);
    if(-1==iRet){
        perror("inet_aton");
    }
    printf("%x\n",myaddr.s_addr);
    printf("%x\n",inet_addr(ip));
    myaddr.s_addr=0xac100ac4;
    printf("%s\n",inet_ntoa(myaddr));
    return 0;
}

