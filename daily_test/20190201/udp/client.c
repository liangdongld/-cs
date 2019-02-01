#include <func.h>
int main(int argc,char **argv){
    args_check(argc,3);
    int socketfd=socket(AF_INET,SOCK_DGRAM,0);
    if(-1==socketfd){
        perror("socket");
        return -1;
    }
    struct sockaddr_in ser;
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(argv[2]));
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    int ret=sendto(socketfd,"1",1,0,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    if(-1==ret){
        perror("sendto");
        return -1;
    }
    char buf[128]={0};
    fd_set rdset;
    socklen_t len;
    while(1){
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(socketfd,&rdset);
        ret=select(socketfd+1,&rdset,NULL,NULL,NULL);
        if(-1==ret){
            perror("select");
            return -1;
        }
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            bzero(buf,sizeof(buf));
            ret=read(STDIN_FILENO,buf,sizeof(buf)-1);
            if(0==ret){
                printf("I will close");
                break;
            }
            sendto(socketfd,buf,strlen(buf)-1,0,(struct sockaddr*)&ser,sizeof(struct sockaddr));
        }
        if(FD_ISSET(socketfd,&rdset)){
            bzero(buf,sizeof(buf));
            len=sizeof(struct sockaddr);
            ret= recvfrom(socketfd,buf,sizeof(buf)-1,0,(struct sockaddr*)&ser,&len);
            if(-1==ret){
                perror("recvfrom");
                return -1;
            }
            printf("%s\n",buf);
        }
    }
    close(socketfd);
    return 0;
}

