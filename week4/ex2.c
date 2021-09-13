#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	for (unsigned i = 0; i < 5; ++i) { 
		fork();
		sleep(5);
	}
}
/*
        |                |-bash---ex2-+-ex2-+-ex2-+-ex2-+-ex2---ex2
        |                |            |     |     |     `-ex2
        |                |            |     |     |-ex2---ex2
        |                |            |     |     `-ex2
        |                |            |     |-ex2-+-ex2---ex2
        |                |            |     |     `-ex2
        |                |            |     |-ex2---ex2
        |                |            |     `-ex2
        |                |            |-ex2-+-ex2-+-ex2---ex2
        |                |            |     |     `-ex2
        |                |            |     |-ex2---ex2
        |                |            |     `-ex2
        |                |            |-ex2-+-ex2---ex2
        |                |            |     `-ex2
        |                |            |-ex2---ex2
        |                |            `-ex2
*/
