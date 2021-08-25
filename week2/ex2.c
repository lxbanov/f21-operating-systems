#include <stdio.h>
#include <string.h>

char input[1024], output[1024];
int main() {
    printf("Type a string: \n");
    gets(input);
    size_t length = strlen(input);
    for (size_t i = length - 1; i + 1; --i) {
        output[length - i - 1] = input[i];
    }
    printf("The reverse of you string is:\n%s", output);
}
