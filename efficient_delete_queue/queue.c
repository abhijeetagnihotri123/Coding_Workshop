#include "queue.h"
struct queue create_queue(int n)
{
    struct queue q;
    q.capacity = n;
    q.size = 0;
    q.s1 = create_stack(n);
    q.s2 = create_stack(n);
    q.last_op = 0; // 0 for push 1 for pop
    return q;
}
int q_isfull(struct queue *q)
{
    return q->size == q->capacity?1:0;
}
int q_isempty(struct queue *q)
{
    return q->size == 0 ? 1:0;
}
int front(struct queue *q)
{
    return top(&q->s2);
}
void destroy_queue(struct queue *q)
{
    free(q->s1.arr);
    free(q->s2.arr);
    q->capacity = 0;
    q->last_op = 0;
    q->size = 0;
}
int q_pop(struct queue *q)
{   
    q->size--;
    q->last_op = 1;
    return pop(&q->s2);
}
void copy_stack(struct stack *s1,struct stack s2)
{   
    while(isempty(s1) != 1)
    {
        pop(s1);
    }
    while(isempty(&s2) != 1)
    {
        int ele = pop(&s2);
        push(s1,ele);
    }
}
void q_push(struct queue *q,int n)
{
    if(q->last_op == 0)
    {
        push(&q->s1,n);
        copy_stack(&q->s2,q->s1);
    }
    else
    {
        q->last_op = 0;
        copy_stack(&q->s1,q->s2);
        push(&q->s1,n);
        copy_stack(&q->s2,q->s1);   
    }
    q->size++;
}

