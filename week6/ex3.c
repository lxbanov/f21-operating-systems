#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int a_time;
    int b_time;
} p_info;
typedef struct {
    int ct;
    int tat;
    int wt;
} ex_info;
typedef struct {
    int exec_at;
    int rm;
    char is_waiting;
    char finished;
} ex_run;

#define  true    1
#define  false   0

void round_robin(int n, p_info *proc, int quantum, int maxT, ex_info **ex, float *atm, float *awt) {
    *ex = (ex_info *) calloc(n, sizeof(ex_info));
    ex_run *ex_r = (ex_run *) calloc(n, sizeof *ex_r);
    for (int i = 0; i < n; i++) {
        ex_r[i].rm = proc[i].b_time;
    }
    int current = 0, next_break = quantum - 1;
    ex_r[current].rm = proc[current].b_time;
    for (int t = 0; t <= maxT; ++t) {
        if (t > 0) {
            ex_r[current].rm--; // decrease remaining time
        }

        if (t == next_break || ex_r[current].rm == 0) {
            if (ex_r[current].rm == 0) {
                ex_r[current].finished = true;
                (*ex)[current].ct = t;
            }
            else ex_r[current].is_waiting = true;
            int iters = 0;
            do {
                current = (current + 1) % n;
                iters++;
            } while (ex_r[current].finished == true && iters <= n);

            next_break = t + quantum;
        }

        for (int i = 0; i < n; ++i) {
            if (proc[i].a_time <= t && current != i && ex_r[i].finished == false) {
                (*ex)[i].wt++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        (*ex)[i].tat = (*ex)[i].wt + proc[i].b_time;
        *atm += (float)(*ex)[i].tat;
        *awt += (float)(*ex)[i].wt;
    }
    *atm /= (float) n;
    *awt /= (float) n;
    free(ex_r);

}



const char* print_pattern = "P%d\t%d\t%d\t%d\t%d\t%d\n";
const char* print_header = "P#\tAT\tBT\tCT\tTAT\tWT\n\n";

int main(void) {
    int n, q;
    float atm = 0, awt = 0;
    scanf("%d%d", &n, &q);
    p_info *arr = (p_info *) calloc(n, sizeof(p_info));
    ex_info *exInfo;
    for (int i = 0; i < n; ++i) {
        arr[i].i = i;
        scanf("%d%d", &arr[i].a_time, &arr[i].b_time);
    }
    round_robin(n, arr, q, 50, &exInfo, &atm, &awt);
    printf(print_header);
    for (int i = 0; i < n; ++i) {
        printf(print_pattern, arr[i].i, arr[i].a_time, arr[i].b_time, exInfo[i].ct, exInfo[i].tat, exInfo[i].wt);
    }
    printf("\nAverage Turnaround Time: %f\n", atm);
    printf("Average Waiting Time: %f\n", awt);
    free(exInfo);
    free(arr);

}