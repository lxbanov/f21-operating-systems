#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char age;
    int ref;
    int free;
} page;

int find_free(page *pages, int size) {
    for (int i = 0; i < size; i++) {
        if (pages[i].free == 1) {
            return i;
        }
    }
    return -1;
}

int find_entry(int ref, page *pages, int size) {
    for (int i = 0; i < size; i++) {
        if (pages[i].ref == ref) {
            return i;
        }
    }
    return -1;
}

int find_min_age(page *pages, int size) {
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (pages[i].age < pages[index].age) {
            index = i;
        }
    }
    return index;
}

int set(int _i, int reference, page *pages, int size) {
    pages[_i].age = pages[_i].age >> 1 | 128;
    pages[_i].ref = reference;

    for (int i = 0; i < size; i++) {
        if (i != _i) {
            pages[i].age = pages[i].age >> 1;
        }
    }
    return 0;
}

int ref(int reference, page *pages, int size) {
    int index;
    int same = find_entry(reference, pages, size);
    if (same != -1) {
        set(same, reference, pages, size);
        return 0;
    } else {
        int free = find_free(pages, size);
        if (free != -1) {
            index = free;
            pages[free].free = 0;
        } else {
            index = find_min_age(pages, size);
        }
    }

    set(index, reference, pages, size);
    return 1;
}

int main() {
    int page_count;
    scanf("%d", &page_count);
    page *pages = malloc(sizeof(page) * page_count);
    int missCount = 0;

    FILE *file;
    file = fopen("input.txt", "r");

    for (int i = 0; i < page_count; i++) {
        pages[i].ref = -1;
        pages[i].free = 1;
        pages[i].age = 0;
    }

    int in;
    int size = 0;
    while (fscanf(file, "%d", &in) == 1) {
        size++;
        missCount = missCount + ref(in, pages, page_count);
    }

    float missRatio = (float) missCount / (float) size;
    float hitRatio = 1 - missRatio;
    printf("Miss ratio: %f\nHit ratio: %f\n", missRatio, hitRatio);
    free(pages);
    fclose(file);
    free(file);
    return 0;
}