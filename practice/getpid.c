#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	printf("%d\n", getppid());
	int id = fork();
	
	if (id == 0)
	{
		printf("Child id : %d, process : %d, getppid : %d\n", id, getpid(), getppid());
		sleep(1);
	}
	else
	{
		printf("Parent id : %d, process : %d, getppid : %d\n", id, getpid(), getppid());
	}
	int res = wait(NULL);
	if (res == -1)
		printf("No Children to wait for\n");
	else
		printf("%d finished exection\n", res);
}