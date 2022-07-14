#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}
	if (pid == 0)
	{
		execlp("mkfifo", "mkfifo", "sum", NULL);
	} else {
		wait(NULL);
		printf("Success\n");
		printf("Some post processing goes here\n");
	}
	return 0;
}