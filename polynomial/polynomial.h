#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct __poly
{
    //List L;
    float coeff;
    int exponent;
    struct __poly *next;
}*poly;
poly string_to_poly(char*);
int token_to_term(char*,float*,int*); 
poly create_poly(); // will hold the dummy node
void insert_term(poly,int,float);
int power(int,int);
void display_poly(poly);
poly add_poly(poly,poly);
poly sub_poly(poly,poly);
poly multiply_poly(poly,poly);
void destroy_poly(poly);
#endif