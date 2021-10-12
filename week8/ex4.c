#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <cstring>
#include <unistd.h>
#define _100MB 100 * 1024 * 1024

int main(void) {
	rusage* usage = (rusage*) calloc(sizeof(rusage), 1);
	for (int i = 0; i < 10; ++i) {
		memset(calloc(_100MB, 1), 0, _100MB);
		getrusage(RUSAGE_SELF, usage);
		printf("Allocated 100 MB\nSystem time used: %d\nMaximum Resident Set Size: %d\nIntegral Shared Memory Size: %d\nIntegral Unshared Data Size: %d\nIntegral Unshared Stack Size:%d\n\n", usage->ru_stime, usage->ru_maxrss, usage->ru_ixrss, usage->ru_idrss, usage->ru_isrss);
		sleep(1);
	}
	free(usage);	
}
