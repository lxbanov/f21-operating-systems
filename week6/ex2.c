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

void calculate_sjf(int n, p_info *proc, int maxT, ex_info **ex, float *atm, float *awt) {
    *ex = (ex_info *) calloc(n, sizeof(ex_info));
    ex_run *ex_r = (ex_run *) calloc(n, sizeof *ex_r);
    int current = -1; // current running process number
    for (int t = 0; t <= maxT; ++t) {
        if (current != -1) { // if some process is running
            ex_r[current].rm--; // decrease remaining time

        }
        if (ex_r[current].rm == 0) { // if completed
            (*ex)[current].ct = t;
            ex_r[current].finished = true;
            current = -1;
        }
        if (current == -1) {
            int temp = -1;
            for (int i = 0; i < n; ++i) {
                if (proc[i].a_time <= t && ex_r[i].finished == false) {
                    if ((temp != -1 && proc[i].b_time < proc[temp].b_time) || temp == -1) {
                        temp = i;
                    }
                }

                // First Come First Run Code:

                /*if (proc[i].a_time <= t && ex_r[i].finished == false) {
                    if ((temp != -1 && proc[i].a_time < proc[temp].a_time) || temp == -1) {
                        temp = i;
                    }
                }*/
            }

            current = temp;
            if (current >= 0 && current < n) {
                ex_r[current].is_waiting = false;
                ex_r[current].rm = proc[current].b_time;
            }

        }
        for (int i = 0; i < n; ++i) {
            if (proc[i].a_time <= t && i != current && ex_r[i].finished == false) {
                ex_r[i].is_waiting = true; // mark as waiting
                (*ex)[i].wt++; // increase waiting time
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
    int n;
    float atm = 0, awt = 0;
    scanf("%d", &n);
    p_info *arr = (p_info *) calloc(n, sizeof(p_info));
    ex_info *exInfo;
    for (int i = 0; i < n; ++i) {
        arr[i].i = i;
        scanf("%d%d", &arr[i].a_time, &arr[i].b_time);
    }
    calculate_sjf(n, arr, 25, &exInfo, &atm, &awt);
    printf(print_header);
    for (int i = 0; i < n; ++i) {
        printf(print_pattern, arr[i].i, arr[i].a_time, arr[i].b_time, exInfo[i].ct, exInfo[i].tat, exInfo[i].wt);
    }
    printf("\nAverage Turnaround Time: %f\n", atm);
    printf("Average Waiting Time: %f\n", awt);
    free(exInfo);
    free(arr);

}