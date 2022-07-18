#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int global;

int main()
{
	int automatic;
	int *heap;
	pid_t pid;

	global = 10;
	automatic = 10;
	heap = (int *)malloc(sizeof(int));

	if (!heap)
		return 0;
	*heap = 10;
	pid = fork();
	if (pid == -1)
	{
		free(heap);
		return 1;
	}
	else if (!pid)
	{
		printf("Child : Before operations -> Global : %d, Auto : %d, Heap : %d\n", global, automatic, *heap);
		global += 10;
		automatic += 10;
		*heap += 10;
		printf("Child : After operations -> Global : %d, Auto : %d, Heap : %d\n", global, automatic, *heap);
	}
	else if (pid)
	{
		printf("Parent : Before operations -> Global : %d, Auto : %d, Heap : %d\n", global, automatic, *heap);
		global += 5;
		automatic += 5;
		*heap += 5;
		printf("Parent : After operations -> Global : %d, Auto : %d, Heap : %d\n", global, automatic, *heap);
	}
}