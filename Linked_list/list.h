#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct __list
{
    int data;
    struct __list *next;
}*List;
List create_list(int);
void length(List,int*);
int check_for_inner_loop(List); // 1 for loop present 0 for loop not present
#endif