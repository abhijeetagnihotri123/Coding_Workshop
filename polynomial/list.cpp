#include "list.h"
void display_list(List p)
{
    Node *start = p.L->next;
    while(start != p.L)
    {
        cout<<start->data<<" ";
        start = start->next;
    }
    cout<<endl;
}
void insert(List p,int x)
{
    Node *ptr = new Node(x);
    if(p.L->next == NULL)
    {
        p.L->next = ptr;
        ptr->next = p.L;
    }
    else
    {
        ptr->next = p.L->next;
        p.L->next = ptr;   
    }
}
void Delete(List p,int x)
{
    Node *L = p.L;
    Node *start = L;
    L->data = x;
    while(start->next->data != x)
    {
        start = start->next;
    }
    if(start->next != L)
    {   
        Node *temp = start->next;
        start->next = start->next->next;
        delete(temp);
    }
    L->data = -1;
}
