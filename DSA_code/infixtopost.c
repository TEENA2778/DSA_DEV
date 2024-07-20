#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 100
char stack[N];

char infix[N];
char postfix[N];

int top=-1;

void push(char item){
    if(top==N-1)
    {
        printf("queue overflow");
        return;
    }
    stack[++top]=item;
}
char pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    return stack[top--];
}
int isEmpty()
{
    return top==-1;
}


int precedence(char symbol)
{
    switch(symbol){

    
    case '^':
    return 3;
    case '*':
    case '/':
    return 2;
    case '+':
    case '-':
    return 1;
    default:
    return -1;

}}

void infixToPostfix()
{
    char symbol;
    int i=0;
    int j=0;
    int next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
            case '(':
                push(symbol);
                break;
           case ')':
           while((next=pop())!='(')
           {
            postfix[j++]=next;
           }
           break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
        }
    }


}
int main()
{
    printf("enter the infix express");
    gets(infix);
    infixToPostfix(); // Corrected function name
    printf("Postfix expression: %s\n", postfix); 
    return 0;
}
