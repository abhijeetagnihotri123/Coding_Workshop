#include "list.h"
void display_list(List &p)
{
    Node *start = p.L->next;
    while(start != p.L)
    {
        cout<<"("<<start->power<<" "<<start->coeff<<") ";
        start = start->next;
    }
    cout<<endl;
}
void insert(List &p,int x,int y)
{
    Node *ptr = new Node(x,y);
    Node *L = p.L;
    if(L->next == NULL)
    {
        L->next = ptr;
        ptr->next = L;
    }
    else
    {   
        Node *start = L;
        L->power = x+1;
        while(start->next->power < x)
        {
            start = start->next;
        }
        ptr->next = start->next;
        start->next = ptr;
    }
}
void Delete(List &p,int x)
{
    Node *L = p.L;
    Node *start = L;
    L->coeff = x;
    while(start->next->coeff != x)
    {
        start = start->next;
    }
    if(start->next != L)
    {   
        Node *temp = start->next;
        start->next = start->next->next;
        delete(temp);
    }
    L->coeff = L->power = -1;
}