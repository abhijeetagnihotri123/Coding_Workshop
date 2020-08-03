#include "matrix_define.h"

int matrix_add(int a[MAX_SIZE][MAX_SIZE],int n,int m)
{   
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum+=a[i][j];
        }
    }
    return sum;
}

void initialise_matrix(int a[MAX_SIZE][MAX_SIZE]) // this function initialises a matrix with dummy elements
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {   
            int n = (i<<1);
            int m = (j<<2);
            a[i][j] = n+m;
        }
    }
}
