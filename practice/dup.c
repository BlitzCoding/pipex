#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd1, fd2;
	char message[32] = {"message via fd2\n"};

	fd1 = open("./arg0", O_RDWR | O_CREAT, S_IRUSR|S_IWUSR);
	if (fd1 < 0)
	{
		printf("file open error\n");
		exit(0);
	}

	fd2 = dup(fd1);

	write(fd2, message, strlen(message));
	printf("fd1 : %d, fd2: %d \n", fd1, fd2);
	close(fd1);
	close(fd2);
}