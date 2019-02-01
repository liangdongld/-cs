#include <func.h>
int main(int argc, char **args) {
	args_check(argc, 3);
	int servicefd = socket(AF_INET, SOCK_STREAM, 0);
	if (servicefd == -1) {
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	ser.sin_family = AF_INET;
	ser.sin_port = htons(atoi(args[2]));
	ser.sin_addr.s_addr = inet_addr(args[1]);
	int ret;
	ret = bind(servicefd, (struct sockaddr*)&ser, sizeof(struct sockaddr));
	listen(servicefd, 5);
	int newfd;
	struct sockaddr_in client;
	bzero(&client, sizeof(struct sockaddr_in));
	socklen_t len = sizeof(struct sockaddr_in);
	newfd= accept(servicefd, (struct sockaddr*)&client, &len);
	char buf[128];
	bzero(buf, sizeof(buf));
	int epfd = epoll_create(1);
	struct epoll_event even, ev[2];
	even.events = EPOLLIN;
	even.data.fd = STDIN_FILENO;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &even);
	if (-1 == ret) {
		perror("epoll_ctl");
		return -1;
	}
	even.data.fd = newfd;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, newfd, &even);
	if (-1 == ret) {
		perror("epoll_ctl1");
		return -1;
	}
	int revlowvalue = 10;
	ret = setsockopt(newfd, SOL_SOCKET, SO_RCVLOWAT, &revlowvalue, sizeof(int));
	int i, fdreadynum;
	while (1) {
		bzero(ev, sizeof(ev));
		fdreadynum = epoll_wait(epfd, ev, 2, -1);//epoll_wait 只把可读的传出来
		for (i = 0; i < fdreadynum; i++) {
			if (STDIN_FILENO == ev[i].data.fd) {
				bzero(buf, sizeof(buf));
				ret = read(STDIN_FILENO, buf, sizeof(buf)-1);//-1是为了消除\n
				if (0 == ret) {
					printf("close\n");
					goto end;
				}
				send(newfd, buf, strlen(buf) - 1, 0);
			}
			if (newfd == ev[i].data.fd) {
				bzero(buf, sizeof(buf));
				ret = recv(newfd, buf, sizeof(buf)-1, 0);
				if (0 == ret) {
					printf("close\n");
					goto end;
				}
				printf("%s\n", buf);
			}
		}
	}
end:
	close(newfd);
	close(servicefd);
}
