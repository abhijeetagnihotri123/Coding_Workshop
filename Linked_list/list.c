#include "list.h"
List create_list(int n)
{
    List l;
    l = (List)malloc(sizeof(struct __list));
    l->data = n;
    l->next = NULL;
    return l;
}
void length(List L,int *c)
{
    *c = 0;
    while(L != NULL)
    {   
        *c = *c + 1;
        L = L->next;
    }
}
int check_for_inner_loop(List l)
{
    List t = l->next;
    l->data = -2147483648;
    while (t != NULL && t->data != -2147483648)
    {   
        t->data = -2147483648;
        t = t->next;
    }
    return t == NULL?0:1;
}