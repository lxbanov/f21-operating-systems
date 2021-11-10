#include <stdio.h>

#define true 1
#define false 0
#define N 5
#define M 3

typedef struct {
    int id;
    int done;
    int C[M];
    int R[M];
} p_t;

int A[M];
p_t proc[N];
int E[M];


int test() {
    for (int pid = 0; pid < N; pid++) {
        if (proc[pid].done == true) {
            continue;
        }
        char okay = true;
        for (int j = 0; j < M; j++) {
            if (proc[pid].R[j] > A[j]) {
                okay = false;
                break;
            }
        }
        if (okay) {
            return pid;
        }
    }
    return -1;
}


void flush(int pid) {
    for (int j = 0; j < M; j++) {
        A[j] = A[j] + proc[pid].C[j];
        proc[pid].C[j] = 0;
        proc[pid].R[j] = 0;
        proc[pid].done = true;
    }
}

void input(char *filename) {
    FILE *input;
    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Could not find the input file\n");
    } else {
        for (int j = 0; j < M; j++) {
            fscanf(input, "%d", &E[j]);
        }
        for (int j = 0; j < M; j++) {
            fscanf(input, "%d", &A[j]);
        }
        for (int pid = 0; pid < N; pid++) {
            proc[pid].id = pid;
            proc[pid].done = false;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                fscanf(input, "%d", &proc[i].C[j]);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                fscanf(input, "%d", &proc[i].R[j]);
            }
        }
    }
}

void print(int isVerdict) {
    printf(isVerdict ? "\n======= Verdict =======\n" : "\n======= State =======\n");
    printf("Existing: (");
    for (int j = 0; j < M; j++) {
        printf("%d", E[j]);
        printf(j + 1 == M ? ")\n" : ", ");
    }
    printf("Available: (");
    for (int j = 0; j < M; j++) {
        printf("%d", A[j]);
        printf(j + 1 == M ? ")\n" : ", ");
    }

    for (int PID = 0; PID < N; PID++) {
        printf("Process %d ", proc[PID].id);
        if (isVerdict) {
            if (proc[PID].done == false) {
                printf("is in dead lock.\n");
            } else {
                printf("is done.\n");
            }
        } else {
            if (proc[PID].done == false) {
                printf("has not finished yet. Requires: [");
                for (int j = 0; j < M; j++) {
                    printf("%d", proc[PID].R[j]);
                    printf(j + 1 == M ? "]\n" : ", ");
                }
            } else {
                printf("is done.\n");
            }
        }
    }
}

int main() {
    int candidate;
    input("input_dl.txt");
    while (true) {
        print(false);
        candidate = test();
        if (candidate == -1) {
            break;
        }
        flush(candidate);
    }
    print(true);
    return 0;
}