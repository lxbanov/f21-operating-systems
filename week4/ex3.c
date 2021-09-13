#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int proceed() {
	char* line = (char *) calloc(0, 256);
	size_t len = 256;
	getline(&line, &len, stdin);
	char* argv[] = {line, (char *) 0};
	argv[0][strlen(argv[0]) - 1] = 0;
	if (strcmp(argv[0], "quit") == 0) {
		return 0;
	}
     	pid_t pid = fork();
	if (pid == 0) {
		execvp(argv[0], argv);
		return 0;
	} else {
	       return proceed();
	}
	
}

int main(int argc, char* argv[], char* env[]) {
	printf("Terminal emulator\nType 'quit' to stop the process\n");
	proceed();
}

