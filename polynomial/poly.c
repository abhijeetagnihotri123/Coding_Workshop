#include "polynomial.h"

poly create_poly()
{
    // create_header 
    poly t;
    t = (poly)malloc(sizeof(struct __poly));
    t->next = NULL;
    t->coeff = 0.0;
    t->exponent = 0;
    return t;
}
void insert_term(poly p,int exponent,float coeff)
{   
    poly prev;
    poly term;
    prev = p;
    int flag = 1;
    while(prev->next != NULL)
    {
        if(prev->next->exponent < exponent)
        {
            break;
        }
        else if(prev->next->exponent == exponent)
        {
            prev->next->coeff += coeff;
            if(prev->next->coeff == 0)
            {
                term = prev->next;
                prev->next = term->next;
                free(term);
            }
            flag = 0;
            break;// 
        }
        else
        {
            prev = prev->next;
        }
    }
    if(flag == 1)
    {
        term = (poly)malloc(sizeof(struct __poly));
        term->coeff = coeff;
        term->exponent = exponent;
        term->next = prev->next;
        prev->next = term;
    }
}
int power(int a,int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(a == 1)
    {
        return 1;
    }
    else if(n == 1)
    {
        return a;
    }
    else if(n % 2 == 0)
    {
        return power(a*a,n/2);
    }
    else
    {
        return a * power(a*a,n/2); 
    }
}
float get_value(char *s,int *result)
{
    int n = strlen(s);
    if(s[n-1] == '.')
    {
        *result = 1;
        return 0.0;
    }
    else
    {   
        char s1[1001];
        char s2[1001];
        int k = 0;
        int i = 0;
        float r;
        float r1,r2;
        while(i<n && s[i] != '.')
        {
            s1[k++] = s[i];
            i++;
        }
        s1[k] = '\0';
        r1 = atoi(s1);
        if(i == n-1)
        {
            r2 = 0.0;
        }
        else
        {   
            i++;
            int p = power(10,n-i);
            k = 0;
            while(i<n)
            {
                s2[k++] = s[i];
                i++;
            }
            s2[k] = '\0';
            r2 = atoi(s2);
            r2 = r2/p;
        }
        r = r1 + r2;
        return r;
    }
}
int token_to_term(char *s,float *coeff,int *exponent)
{       
    int result = 0;
    *coeff = 1;
    int n = strlen(s);
    char str[1001];
    int k = 0;
    *coeff = 1.0;
    float p = 1.0;
    *exponent = 0;
    strcpy(str,"");
    int i = 0;
    while(i<n && s[i] != 'x')
    {
        if(s[i] == '*')
        {   
            str[k] = '\0';
            p *= get_value(str,&result);
            if(result == 1)
            {
                break;
            }
            strcpy(str,"");
            k=0;
        } 
        else
        {
            str[k++] = s[i];
        }
        i++;
    }
    if(k>0 && result != 1)
    {
        str[k]='\0';
        p *= get_value(str,&result);
    }
    if(i<n && s[i] == 'x' && result != 1)
    {   
        if(s[i+1] != '^')
        {
            *exponent = 1;
            i++;
        }
        else
        {
            k = 0;
            strcpy(str,"");
            i = i + 2;
            while(i<n && s[i] != '*')
            {   
                if(s[i] == '.')
                {
                    result = 1;
                    break;
                }
                else
                {
                    str[k++] = s[i];
                    i++;
                }
            }
            str[k] = '\0';
        }
        *exponent = atoi(str);
    }
    if(i<n && s[i] == '*' && result != 1)
    {   
        strcpy(str,"");
        k = 0;
        i++;
        while(i<n)
        {
            if(s[i] == '*')
            {   
                str[k] = '\0';
                p *= get_value(str,&result);
                strcpy(str,"");
                k=0;
            }    
            else
            {
                str[k++] = s[i];
            }
            i++;
        }
        if(k>0)
        {
            str[k]='\0';
            p *= get_value(str,&result);
        }
    }
    if(result != 1)
    {
        *coeff = p;
    }
    return result;
}
poly string_to_poly(char *s)
{
    poly p = create_poly();
    char sign = '+';
    int i=0;
    int last_index;
    int k = 0;
    int power,code,flag;
    float coeff;
    char str[1001];
    int n = strlen(s);
    flag = 0;
    if(s[i] == '+' || s[i] == '-')
    {   
        sign = s[i];
        i = 1;
    }
    for(;i<n;i++)
    {
        if(s[i] == '+' || s[i] == '-')
        {   
            str[k] = '\0';
            code = token_to_term(str,&coeff,&power);
            if(code == 0)
            {   
                if(sign == '+')
                {
                    insert_term(p,power,coeff);   
                }
                else
                {
                    insert_term(p,power,-coeff);
                }
            }
            sign = s[i];
            strcpy(str,"");
            k = 0;
            last_index = i;
        }
        else
        {
            str[k++] = s[i];
        }
    }
    last_index++;
    strcpy(str,"");
    k = 0;
    for(;last_index<n;last_index++)
    {
        str[k++] = s[last_index];
    }
    str[k] = '\0';
    code = token_to_term(str,&coeff,&power);
    if(code == 0)
    {   
        if(sign == '+')
        {
            insert_term(p,power,coeff);
        }
        else
        {
            insert_term(p,power,-coeff);
        }
        
    }
    if(code == 1)
    {   
        poly n;
        while(p != NULL)
        {
            n = p;
            p = p->next;
            free(n);
        }
        return NULL;
    }
    return p;
}
void display_poly(poly p)
{
    poly t = p->next->next;
    if(p->next->coeff > 0)
    {
        if(p->next->exponent > 1)
        {
            if(p->next->coeff > 0)
            {
                printf("%fx^%d",p->next->coeff,p->next->exponent);
            }
            else
            {
                printf("%fx^%d",p->next->coeff,t->exponent);
            }
        }
        else if(t->exponent == 1)
        {
            if(t->coeff > 0)
            {
                printf("%fx",p->next->coeff);
            }
            else
            {
                printf("%fx",p->next->coeff);
            }
        }
        else
        {
            if(t->coeff > 0)
            {
                printf("%f",p->next->coeff);
            }
            else
            {
                printf("%f",p->next->coeff);
            }
        }
    }
    while(t != NULL)
    {
        if(t->exponent > 1)
        {
            if(t->coeff > 0)
            {
                printf("+%fx^%d",t->coeff,t->exponent);
            }
            else
            {
                printf("%fx^%d",t->coeff,t->exponent);
            }
            // t->coeff = 0 no term
        }
        else if(t->exponent == 1)
        {
            if(t->coeff > 0)
            {
                printf("+%fx",t->coeff);
            }
            else
            {
                printf("%fx",t->coeff);
            }
        }
        else
        {
            if(t->coeff > 0)
            {
                printf("+%f",t->coeff);
            }
            else
            {
                printf("%f",t->coeff);
            }
        }
        t = t->next;   
    }
    printf("\n");
}
poly add_poly(poly p,poly q)
{
    poly r; // insert takes care of everything
    r = create_poly();
    poly t = p->next;
    while(t != NULL)
    {
        insert_term(r,t->exponent,t->coeff);
        t = t->next;
    }
    t = q->next;
    while(t != NULL)
    {
        insert_term(r,t->exponent,t->coeff);
        t = t->next;
    }
    return r;
}
poly sub_poly(poly p,poly q)
{
    poly r; // same as add invert sign
    r = create_poly();
    poly t = p->next;
    while(t != NULL)
    {
        insert_term(r,t->exponent,t->coeff);
        t = t->next;
    }
    t = q->next;
    while(t != NULL)
    {
        insert_term(r,t->exponent,-t->coeff);
        t = t->next;
    }
    return r;
}
poly multiply_poly(poly p,poly q)
{
    poly r,t1,t2;
    r = create_poly();
    t1 = p->next;
    while(t1 != NULL)
    {       
        t2 = q->next;
        while(t2 != NULL)
        {
            insert_term(r,t1->exponent+t2->exponent,t2->coeff*t1->coeff);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return r;
}
