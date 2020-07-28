#include "prime.h"

int main()
{   
    int a[100];
    generate_primes(a);
    for(int i=0;i<100;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}