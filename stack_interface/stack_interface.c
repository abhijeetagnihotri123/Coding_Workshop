#include "stack_interface.h"

struct stack create_stack(int n)
{
    struct stack s;
    s.capacity = n;
    s.size = 0;
    s.top = -1;
    s.arr = (int*)malloc(n * sizeof(int));
    return s;
}
void push(struct stack *s,int data)
{
    if(isfull(s) == 1)
    {
        printf("Stack overflowed cannot enter more elements\n");
    }
    else
    {
        s->arr[++s->top] = data;
        s->size++;
    }
}
int pop(struct stack *s)
{
    if(s->size == 0)
    {
        return -1;
    }
    else if(s->size == 1)
    {
        s->size = 0;
        int ele = s->arr[s->top];
        s->top = -1;
        return ele;
    }
    else
    {
        int ele = s->arr[s->top];
        s->top--;
        s->size--;
        return ele;
    }
}
int top(struct stack *s)
{
    return s->arr[s->top];
}
int isfull(struct stack *s)
{
    return s->capacity == s->size?1:0;
}
int isempty(struct stack *s)
{
    return s->size == 0?1:0;
}