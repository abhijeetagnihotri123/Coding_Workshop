#include "postfix.h"
#include <string.h>
int postfix_evaluator(char *e) 
{
    int n = strlen(e); 
    struct stack s;
    s = create_stack(n);
    int a,b;
    for(int i=0;i<n;i++)
    {
        char ch = e[i];
        if(ch>='0' && ch<='9')
        {
            a = (int)(ch-'0');
            push(&s,a);
        }
        else
        {   
            if(s.size >= 2)
            {
                a = pop(&s);
                b = pop(&s);
                if(ch == '+')
                {
                    push(&s,a+b);
                }
                else
                {
                    push(&s,a*b);
                }
            }
            else
            {
                push(&s,-1);
                break;   
            }
        }
    }
    if(s.size == 1)
    {
        a = pop(&s);
        return a;
    }
    else
    {
        return -1;
    }
}