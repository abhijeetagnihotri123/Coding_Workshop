#include "list.h"

int main()
{
    List l;
    l = create_list(1);
    l->next = create_list(2);
    l->next->next = create_list(3);
    l->next->next->next = create_list(4);
    l->next->next->next->next = create_list(5);
    l->next->next->next->next->next = create_list(6);
    l->next->next->next->next->next->next = create_list(7);
    l->next->next->next->next->next->next->next = l->next->next->next; 
    int code = check_for_inner_loop(l);
    if(code == 1)
    {
        printf("There is a loop in the given list\n");
    }
    else
    {
        printf("List is normal\n");
    }
    return 0;
}