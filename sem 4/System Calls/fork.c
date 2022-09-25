#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		printf("fork failed");
		return 1;
	}
	else if (pid == 0)
	{
		printf("blah");
		execlp("/bin/ls", "ls", NULL);
	}
	else
	{
		wait(NULL);
		printf("Process created: %d", getpid());
	}
	return 0;
}