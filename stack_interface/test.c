#include "stack_interface.h"

int main()
{
    struct stack s;
    s = create_stack(10);
    push(&s,2);
    push(&s,3);
    push(&s,5);
    push(&s,7);
    while(!isempty(&s))
    {
        printf("%d\n",pop(&s));
    }
    return 0;
}