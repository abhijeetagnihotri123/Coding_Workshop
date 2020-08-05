#include "queue.h"

int main()
{   
    struct queue q;
    q = create_queue(10);
    q_push(&q,1);
    q_push(&q,2);
    q_push(&q,3);
    q_push(&q,4);
    q_push(&q,5);
    printf("%d\n",front(&q));
    q_pop(&q);
    q_pop(&q);
    q_push(&q,6);
    printf("%d\n",q_pop(&q));
    printf("%d\n",q_pop(&q));
    printf("%d\n",q_pop(&q));
    printf("%d\n",q_pop(&q));
    return 0;
}