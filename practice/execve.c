#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv)
{
	char **new_argv;
	char command[] = "ls";
	int idx;

	new_argv = (char **)malloc(sizeof(char *) * (argc + 1));

	new_argv[0] = command;

	for (idx = 1; idx < argc; idx++)
		new_argv[idx] = argv[idx];

	new_argv[idx] = NULL;
	if (execve("/bin/cat", new_argv, environ) == -1)
	{
		fprintf(stderr, "progmaer excve errr : %s\n", strerror(errno));
		return 1;
	}


	printf("nono");
	return 0;
}