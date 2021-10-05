#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int * 
reallocate( int* ptr, size_t new_size ) {
	if (ptr == NULL) {
		return (int *) malloc(sizeof(int) * new_size);
	} else {
		int* chunk = (int*) malloc(sizeof(int)  * new_size);
		memcpy(chunk, ptr, sizeof(int) * new_size);
		free(ptr);
		return chunk;
	}
}
int main() {
	int* a = (int *) malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; ++i) {
		a[i] = 2 * i - 23 + i * i;
		printf("%d ", a[i]);
	}
	printf("\n");
	a = (int *) reallocate (a, 10);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	free(a);
}
