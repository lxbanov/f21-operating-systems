#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

typedef unsigned char byte;

int main(void) {
	byte times = 0;
	while (times < 20) {
		memset(calloc(2000 * 1024 * 1024, 1), 0, 2000 * 1024 * 1024);
		 printf("Allocated 2000MB (%d)\n", times);	
		sleep(1);
		++times;
	}
}
/*
 * So, the top command shows the list of processes and some quantities such are 
 * the amount of allocated physical and virtual memory.
 * As ex2 process reaches the large value of physical memory allocated, it starts 
 * to be swapped between physical and virtual memory.
 * Actually, the size of virtual memory allocated by this process became much larger than my RAM capacity (20.6 GB > 16 GB),
 * so it should have used the hard drive to create such an illusion.
 */
