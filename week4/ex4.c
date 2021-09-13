#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int proceed() {
	char* line = (char *) calloc(0, 256);
	size_t len = 256;
	getline(&line, &len, stdin);
	int space = 0;
	for (int i = 0; i < strlen(line); ++i) {
		if (line[i] == ' ')
			++space;
	}
	char* argv[space + 2];
	argv[space + 1] = 0;
	for (int i = 0, g = 0; i <= space; ++i) {
		int j = 0, _j = 0;
		while (line[g + j] != ' ' && g + j + 1 < strlen(line)) {
			++j;
		}
	        argv[i] = (char *) calloc(0, j + 1);
		_j = j;
		while (--j + 1) {
		       argv[i][j]  = line[g + j];	
		}
		g = _j + 1;
	}
	if (strcmp(argv[0], "quit") == 0) {
		return 0;
	}
     	pid_t pid = fork();
	if (pid == 0) {
		execvp(argv[0], argv);
		free(line);
		for (int i = 0; i < space + 1; ++i) {
			free(argv + i);
		}
		return 0;
	} else {
		free(line);
		for (int i = 0; i < space + 1; ++i) {
			free(argv + i);
		}
	       return proceed();
	}
	
}

int main(int argc, char* argv[], char* env[]) {
	printf("Terminal emulator\nType 'quit' to stop the process\n");
	proceed();
}

