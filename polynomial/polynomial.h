#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H
#include "list.h"
struct poly
{
    List L;
};
void parse_expression(string&,poly&);
void Insert(poly&,int,int);
void display_poly(poly&);
void add_poly(poly*,poly*,poly*);
void sub_poly(poly*,poly*,poly*);
void multiply_poly(poly*,poly*,poly*);
#endif