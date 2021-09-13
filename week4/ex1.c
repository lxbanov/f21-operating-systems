#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int n = (1 << 16) + 3553;
	pid_t pid = fork();
	if (pid == 0) 
		printf("Hello from child [%d - %d]\n", pid, n);
	else 
		printf("Hello from parent [%d - %d]\n", pid, n);
}

