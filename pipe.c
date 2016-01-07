#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd[2];
	pid_t pid;
	char readbuf[1024];

	if(pipe(fd) == -1) {
		printf("error in pipe");
		return 1;
	}

	int *read_fd = &fd[0];
	int *write_fd = &fd[1];

	pid = fork();
	if(pid == -1) {
		printf("error in fork");
	}
	else if(pid == 0) {
		char *str = "hello, world";
		write(*write_fd, str, strlen(str));
		printf("child process send: %s\n", str);
	}
	else {
		read(*read_fd, readbuf, sizeof(readbuf));
		printf("parent process receive: %s\n", readbuf);
		
	}

}
