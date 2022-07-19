#include <stdio.h>

int main(int ac, char **argv, char **envp)
{
	for (int i = 0; i < 80; i++)
	{
		printf("<%d> : %s\n", i, envp[i]);
	}
}