#include "postfix.h"

int main()
{   
    char expression1[101] = "23+56+98+55+*++";// should return 186
    char expression2[101] = "235+*"; // should return 16
    char expression3[101] = "23+56+98+55+*+++"; // invalid expression should return -1
    int n1,n2,n3;
    n1 = postfix_evaluator(expression1);
    n2 = postfix_evaluator(expression2);
    n3 = postfix_evaluator(expression3);
    printf("%d %d %d",n1,n2,n3); 
    return 0;
}