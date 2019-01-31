#include <func.h>
int main(int argc,char **argv) {
	args_check(argc, 3);
	int client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == client_fd) {
		perror("socket");
		return -1;
	}
	struct sockaddr_in client;
	memset(&client, 0, sizeof(struct sockaddr));
	client.sin_family = AF_INET;
	client.sin_port = htons(atoi(argv[2]));
	client.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(client);
	int ret = connect(client_fd, (struct sockaddr*)&client,len);
    if(-1==ret){
        perror("connect");
        return -1;
    }
    char buf[128];
    memset(buf,0,sizeof(buf));
	read(STDIN_FILENO, buf, sizeof(buf));
	send(client_fd, buf, sizeof(buf), 0);
	memset(&buf, 0, sizeof(buf));
	recv(client_fd, buf, sizeof(buf), 0);
	printf("%s", buf);
	close(client_fd);
	return 0;
}
