#include <func.h>
int main(int argc,char **argv) {
	args_check(argc, 3);
	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == serverfd) {
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser, 0, sizeof(struct sockaddr));
	ser.sin_family = AF_INET;
	ser.sin_port = htons(atoi(argv[2]));
	ser.sin_addr.s_addr =inet_addr(argv[1]);
	int ret;
	ret = bind(serverfd, (struct sockaddr*)&ser, sizeof(struct sockaddr));
	if (-1 == ret) {
		perror("bind");
		return -1;
	}
	listen(serverfd, 5);
	int new_fd;
	struct sockaddr_in client;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	memset(&client, 0, sizeof(client));
	new_fd = accept(serverfd, (struct sockaddr*)&client, &addrlen);
	if (-1 == new_fd) {
		perror("accept");
		return -1;
	}
	char buf[128];
    memset(buf,0,sizeof(buf));
    ret = recv(new_fd, buf, sizeof(buf), 0);
	printf("%s", buf);
    memset(buf,0,sizeof(buf));
	read(STDIN_FILENO, buf, sizeof(buf));
	send(new_fd, buf, sizeof(buf),0);
	close(new_fd);
	close(serverfd);
	return 0;
}
