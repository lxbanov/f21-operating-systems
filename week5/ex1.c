#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

void* thread_fn(void* arg) {
	int j = *(int*) arg;
	printf("Hello from the thread number %d\n", j + 1);
	return 0;
}
int main() { 
	int n;
	scanf("%d", &n);
	pthread_t *th = (pthread_t *)calloc(0, sizeof (pthread_t) * n);
	for (int i = 0; i < n; ++i) {
		pthread_create(th + i, 0, &thread_fn, &i);
		pthread_join(th[i], 0);
	}
	free(th);
	//pthread_exit(0);
}
