#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t fpid;
	
	fpid = fork();

	if(fpid < 0) {
		printf("error");
	}
	else if(fpid == 0) {
		printf("child process, id is %d\n", getpid());
	}
	else {
		printf("parent process, id is %d\n", getpid());
	}


	return 0;
}
