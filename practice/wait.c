#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	
	int id = fork();
	wait(NULL);
	int n;

	if (id == 0)
		n = 1;
	else
		n = 5;
	
	
	for (int i = 1; i < 5; i++)
	{
		printf("%d ", n * i);
		fflush(stdout);
	}
	
	printf("\n");
	
}