#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	//executes date command
	execlp("/usr/bin/date", "date", NULL);
	//executes cal command
	execlp("/usr/bin/cal", "cal", NULL);
	//executes ls command
	execlp("/usr/bin/ls", "ls", NULL);
	return 0;
}