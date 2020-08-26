#include "polynomial.h"
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
            cout<<coefficient<<" "<<exponent<<endl;
            str = "";
            insert(p.L,exponent,coefficient);
        }
        else
        {
            str+=s[i];   
        }
    }
    coefficient = extract_term(str,exponent,sign);
    cout<<coefficient<<" "<<exponent<<endl;
    insert(p.L,exponent,coefficient);
}
void add_poly(poly *p,poly *q,poly *r)
{

}
void sub_poly(poly *p,poly *q,poly *r)
{

}
void multiply_poly(poly *p,poly *q,poly *r)
{
    
}
int main()
{   
    string s = "2*x^3+3x^12+49";
    poly p;
    parse_expression(s,p);
    display_list(p.L);
    return 0;
}