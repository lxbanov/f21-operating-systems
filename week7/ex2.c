#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	printf("Input the array size: \n");
	scanf("%d", &n);
	int* a = (int*) calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i) {
		a[i] = i;
		printf("%d ", a[i]);
	}
	free(a);
}
