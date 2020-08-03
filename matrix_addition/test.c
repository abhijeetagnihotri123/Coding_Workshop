#include "matrix_define.h"

int a[MAX_SIZE][MAX_SIZE];
int main()
{   
    initialise_matrix(a);
    int n = 4;
    int m = 6;
    int sum = matrix_add(a,n,m);
    printf("%d",sum);
    return 0;
}