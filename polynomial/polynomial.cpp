#include "polynomial.h"
int extract_term(string &s,int &exponent,char &sigh)
{   
    string str = "";
    int p,i,j,x;
    p = 1;
    int n = s.length();
    exponent = 0;
    int x_index,exp_index;
    x_index = -1;
    for(i=0;i<n;i++)
    {
        if(s[i] == 'x')
        {   
            x_index=i;
            for(j=i+2;j<n;j++)
            {   
                exp_index = j;
                if(s[j] == '*')
                {   
                    break;
                }
                str+=s[j];
            }
            if(str.length()>0)
            {
                exponent = stoi(str);
            }
            str = "";
        }
    }
    if(x_index != -1)
    {
        s.erase(x_index,exp_index);
    }
    n = s.length();
    str = "";
    for(int i=0;i<n;i++)
    {
        if(s[i] == '*')
        {
            x = stoi(str);
            str = "";
            p *= x;
        }
        str+=s[i];
    }
    x = stoi(str);
    p *= x;
    p = sigh=='+'?p:p*-1;
    return p;
}
void parse_expression(string &s,poly *p)
{
    string str = "";
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
            cout<<coefficient<<" "<<exponent<<endl;
        }
        else
        {
            str+=s[i];   
        }
    }
    exponent = extract_term(str,exponent,sign);
    cout<<exponent;
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
    string s;
    poly p;
    s = "+4*x^7+2x^5+4x^1+3";
    parse_expression(s,&p);
    return 0;
}