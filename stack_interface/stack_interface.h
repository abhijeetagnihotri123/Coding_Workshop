#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int capacity;
    int size;
    int top;
    int *arr;
};
struct stack create_stack(int);
void push(struct stack*,int);
int pop(struct stack*);
int isfull(struct stack*);
int isempty(struct stack*);
#endif