#include "prime.h"


int check_prime(int n)
{
    int k = sqrt(n);
    for(int i=2;i<=k;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void generate_primes(int a[])
{
    int c = 0;
    a[0] = 2;
    a[1] = 3;
    c = 98;
    int k = 5;
    int index = 2;
    while(c>0)
    {
        if(check_prime(k) == 1)
        {
            a[index] = k;
            index++;
            c--;
        }
        k = k+2;
    }
}