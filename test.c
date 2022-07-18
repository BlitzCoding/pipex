#include <unistd.h>
#include <stdio.h>

int main(int argc, char **av, char **envp)
{
	for (int i = 0; i < 50; i++)
	{
		printf("%s\n", envp[i]);
	}
}