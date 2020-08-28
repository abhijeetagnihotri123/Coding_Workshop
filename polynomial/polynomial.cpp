#include "polynomial.h"
void Insert(poly &p,int x,int y)
{
    List L = p.L;
    insert(L,x,y);
}
int extract_term(string &s,int &exponent,char &sigh)
{   
    string str1,str2;// = "";
    str1 = str2 = "";
    exponent = 0;
    int p,x;
    p = 1;
    int i = 0;
    int n = s.length();
    exponent = 0;
    bool flag = false;
    for(i=0;i<n;i++)
    {
        if(s[i] != 'x')
        {
            str1 += s[i];
        }
        else
        {
            break;
        }
    }
    str1 += '*';
    if(s[i+1] == '^')
    {
        i = i+2;
        for(;i<n;i++)
        {
            if(s[i] == '*')
            {
                break;
            }
            str2 += s[i];
        }
    }
    else
    {
        i = i+1;
        for(;i<n;i++)
        {
            str1 += s[i];
        }
    }
    if(i == n-1)
    {
        // do nothing
    }
    str1 += '*';
    for(;i<n;i++)
    {
        str1 += s[i];
    }
    if(str2.length()>0)
    {
        exponent = stoi(str2);
    }
    s = "";
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i] == '*')
        {
            s="";
        }
        else
        {   
            s+=str1[i];
            x = stoi(s);
            p *= x;
        }
    }
    return p;
}
void parse_expression(string &s,poly &p)
{
    string str = "";
    s+='+';
    char sign;
    int i=0;
    int exponent,coefficient;
    int n = s.length();
    sign = '+';
    if(s[0] == '+' || s[0] == '-')
    {
        i = 1;
        sign = s[0];
    }
    for(;i<n;i++)
    {
        if(s[i] == '+' || s[i] == '-')
        {
            sign = s[i];
            coefficient = extract_term(str,exponent,sign); 
            str = "";
            Insert(p,exponent,coefficient);
        }
        else 
        {
            str+=s[i];   
        }
    }
}
void add_poly(poly &p,poly &q,poly &r)
{
    Node *L1 = p.L.L;
    Node *L2 = q.L.L;
    Node *start1 = L1->next;
    Node *start2 = L2->next;
    int coeff,exponent;
    while(start1 != L1 && start2 != L2)
    {
        if(start1->power < start2->power)
        {
            coeff = start1->coeff;
            exponent = start1->power;
            Insert(r,exponent,coeff);
            start1 = start1->next;
        }
        else if(start1->power > start2->power)
        {
            coeff = start2->coeff;
            exponent = start2->power;
            Insert(r,exponent,coeff);
            start2 = start2->next;
        }
        else
        {
            coeff = start1->coeff + start2->coeff;
            if(coeff != 0)
            {
                exponent = start1->power;
                Insert(r,exponent,coeff);
            }
            start1 = start1->next;
            start2 = start2->next;   
        }
    }
    while(start1 != L1)
    {
        coeff = start1->coeff;
        exponent = start1->power;
        Insert(r,exponent,coeff);
        start1 = start1->next;
    }
    while(start2 != L2)
    {
        coeff = start2->coeff;
        exponent = start2->power;
        Insert(r,exponent,coeff);
        start2 = start2->next;
    }
}
void sub_poly(poly &p,poly &q,poly &r)
{
    Node *L1 = p.L.L;
    Node *L2 = q.L.L;
    Node *start1 = L1->next;
    Node *start2 = L2->next;
    int coeff,exponent;
    while(start1 != L1 && start2 != L2)
    {
        if(start1->power < start2->power)
        {
            coeff = start1->coeff;
            exponent = start1->power;
            Insert(r,exponent,coeff);
            start1 = start1->next;
        }
        else if(start1->power > start2->power)
        {
            coeff = -start2->coeff;
            exponent = start2->power;
            Insert(r,exponent,coeff);
            start2 = start2->next;
        }
        else
        {
            coeff = start1->coeff - start2->coeff;
            if(coeff != 0)
            {
                exponent = start1->power;
                Insert(r,exponent,coeff);
            }
            start1 = start1->next;
            start2 = start2->next;   
        }
    }
    while(start1 != L1)
    {
        coeff = start1->coeff;
        exponent = start1->power;
        Insert(r,exponent,coeff);
        start1 = start1->next;
    }
    while(start2 != L2)
    {
        coeff = -start2->coeff;
        exponent = start2->power;
        Insert(r,exponent,coeff);
        start2 = start2->next;
    }
}
void multiply_poly(poly &p,poly &q,poly &r)
{
    Node *L1 = p.L.L;
    Node *L2 = q.L.L;
    List L3 = r.L;
    Node *start1 = L1->next;
    Node *start2 = L2->next;
    Node *aux = NULL;
    int coeff,power;
    while(start1 != L1)
    {   
        start2 = L2->next;
        coeff = start1->coeff;
        power = start1->power;
        while(start2 != L2)
        {
            coeff *= start2->coeff;
            power += start2->power;
            aux = Find(L3,power);
            if(aux != NULL)
            {
                coeff += aux->coeff;
                if(coeff == 0)
                {
                    Delete(L3,power);
                } 
                else
                {
                    aux->coeff = coeff;   
                }
            }
            else
            {
                Insert(r,power,coeff);   
            }
            coeff = start1->coeff;
            power = start1->power;
            start2 = start2->next;
        }
        start1 = start1->next;
    }
}
void display_poly(poly &p)
{
    List L = p.L;
    display_list(L);
}
int main()
{   
    poly p,q,r1,r2,r3;
    int coeff,exponent;
    int n;
    string s1 = "3*x^3+2*x^2+1*x^1";
    string s2 = "2*x^2+1*x^1";
    parse_expression(s1,p);
    parse_expression(s2,q);
    add_poly(p,q,r1);
    sub_poly(p,q,r2);
    multiply_poly(p,q,r3);
    cout<<"Addition\n";
    display_poly(r1);
    cout<<"Subtraction\n";
    display_poly(r2);
    cout<<"Multiplication\n";
    display_poly(r3);
    return 0;
}