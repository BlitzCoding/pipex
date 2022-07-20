#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **av, char **envp)
{
	int file = open(av[1], O_WRONLY);

	dup2(file, STDOUT_FILENO);
	printf("file : %d\n", file);
	printf("goodsadod");

///

	// int pid = fork();
	// int stat;
	// if (pid == 0)
	// {
	// 	sleep(3);
	// 	printf("child end\n");
	// 	return 0;
	// }
	// while (waitpid(pid, &stat, WNOHANG) == 0)
	// {
	// 	printf("waiting\n");
	// 	sleep(1);
	// }
	// printf("parent end\n");

	// char *path = "/bin/asasv";

	// if (access(path, 0) == 0)
	// {
	// 	printf ("okok\n");
	// }
	// else
	// 	printf("fuck you\n");
}