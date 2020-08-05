#ifndef QUEUE_H
#define QUEUE_H
#include "stack_interface.h"

struct queue
{
    int last_op;
    int capacity;
    int size;
    struct stack s1,s2;
};
int q_pop(struct queue *);
void q_push(struct queue *,int);
int q_isfull(struct queue *);
int q_isempty(struct queue *);
int front(struct queue *);
void destroy_queue(struct queue *);
struct queue create_queue(int);
void copy_stack(struct stack *,struct stack);
#endif
