#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int int_var;
    float float_var;
    double double_var;
    printf("Integer: the size of variable is %d, and the maximum value it might be assigned to is \n%d\n",
           sizeof int_var, INT_MAX);
    printf("Float: the size of variable is %d, and the maximum value it might be assigned to is \n%f\n",
           sizeof float_var, FLT_MAX);
    printf("Double: the size of variable is %d, and the maximum value it might be assigned to is \n%lf",
           sizeof double_var, DBL_MAX);
}
