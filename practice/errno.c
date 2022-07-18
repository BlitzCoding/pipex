#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int mode;

	mode = 0;
	mode |= F_OK;
	if (!access("./test.txt", mode))
		printf("File is existing\n");
	else
		printf("File is not existing\n");
	mode &= 0;
	mode |= X_OK;
	if (!access("./test.txt", mode))
		printf("File is executable\n");
	else
		printf("File is not executable\n");
}