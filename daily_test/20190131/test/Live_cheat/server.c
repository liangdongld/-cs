#include <func.h>
int main(int argc, char **argv) {
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
	ser.sin_addr.s_addr = inet_addr(argv[1]);
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
	fd_set rdset;
	while (1) {
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO, &rdset);
		FD_SET(new_fd, &rdset);
		ret = select(new_fd + 1, &rdset, NULL, NULL, NULL);
		if (ret > 0) {
			if (FD_ISSET(STDIN_FILENO, &rdset)) {
				memset(buf, 0, sizeof(buf));
				read(STDIN_FILENO, buf, sizeof(buf));
				send(new_fd, buf, sizeof(buf), 0);
			}
			if (FD_ISSET(new_fd, &rdset)) {
				memset(buf, 0, sizeof(buf));
				recv(new_fd, buf, sizeof(buf), 0);
				printf("%50s", buf);
			}
		}
	}
	close(new_fd);
	close(serverfd);
	return 0;
}

