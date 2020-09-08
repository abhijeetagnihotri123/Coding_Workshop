#include "polynomial.h"
// strtok
int main()
{   
    poly p,q,r;
    char *s = "+2*2.12*x^4*2.21*4.13+0.1*x^3+1.2*x^1+3";
    char *s1 = "2*x^3+4.5*x^2-5.4";
    p = string_to_poly(s);
    q = string_to_poly(s1);
    printf("The polynomials are \n");
    display_poly(p);
    display_poly(q);
    r = add_poly(p,q);
    printf("The addition of the polynomials is\n");
    display_poly(r);
    r = sub_poly(p,q);
    printf("The subtraction of the polynomials is\n");
    display_poly(r);
    r = multiply_poly(p,q);
    printf("The multiplication of the polynomials is\n");
    display_poly(r);
    return 0;
}