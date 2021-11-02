#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int NAME_MAX = 10;
int len = 3;

int main() {
    char *pth = malloc(1 + len + NAME_MAX);
    DIR *dir;
    struct dirent *dp;
    strcpy(pth, "tmp/");
    if ((dir = opendir("tmp")) == NULL) {
        perror("Cannot open tmp");
        exit(1);
    }
    long unsigned *inodes = malloc(sizeof(long unsigned) * 10);
    int *file_count = malloc(sizeof(int) * 10);
    char ***names = malloc(sizeof(char **) * 10);
    for (int i = 0; i < 10; i++) {
        names[i] = malloc(sizeof(char *) * 10);
        file_count[i] = 0;
    }
    int i = 0;
    while ((dp = readdir(dir)) != NULL) {
        int found = 0;
        for (int j = 0; j < 10 && !found; j++) {
            if (inodes[j] == dp->d_ino) {
                found = 1;
                names[j][file_count[j]] = dp->d_name;
                file_count[j]++;
            }
        }
        if (!found) {
            inodes[i] = dp->d_ino;
            names[i][file_count[i]] = dp->d_name;
            file_count[i]++;
            i++;
        }
    }
    for (int _i = 0; _i < 10; _i++) {
        if (file_count[_i] > 1) {
            printf("%lu\n", inodes[_i]);
            for (int j = 0; j < file_count[_i]; j++) {
                printf("-- %s\n", names[_i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}