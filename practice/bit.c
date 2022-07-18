#include <stdio.h>
#include <unistd.h>

int main(int argc, char  **argv)
{
	int i ;

	i = 0;
	while (++i < argc)
	{
		if (!access(argv[i], F_OK))
		{
			if (!unlink(argv[i]))
				printf("File unlink\n");
			else
				printf("File is not unlinkes\n");
		}
		else
			printf("File not exising\n");
	}
	return 0;
}