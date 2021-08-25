#include <stdio.h>
#include <string.h>

int main() {
    unsigned n;
    printf("Type the `n`:\n");
    scanf("%d", &n);
    char out[n][(n << 1) + 1];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - i; ++j) {
            out[i][j] = ' ';
        }
        for (size_t j = n - i; j <= n + i; ++j) {
            out[i][j] = '*';
        }
        for (size_t j = n + i + 1; j <= (n << 1) - 1; ++j) {
            out[i][j] = ' ';
        }
        out[i][n << 1] = '\0';
    }
    for (size_t i = 0; i < n; i++) {
        printf("%s\n", out[i]);
    }
}
