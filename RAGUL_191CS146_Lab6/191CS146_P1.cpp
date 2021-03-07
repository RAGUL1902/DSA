#include<stdio.h>
#define size 50



char stack[size];
int top=-1;


//Functions initializing
void getnexttoken(char*);
void push(char element);
char pop();
int precedence(char element);
void infixtoprefix();
void getnexttoken(char *w);


//
void push(char element)
{
    stack[++top]=element;
}


char pop()
{
    return (stack[top--]);
}


int precedence(char element)
{
    switch(element)
    {
        case'@':return 0;
        case')':return 1;
        case'+':
        case'-':return 2;
        case'*':
        case'/':return 3;
    }
    return 4;
}


void infixtoprefix()
{
    char infix[size],prefix[size],ch,element;
    char* x;
    int i=0,l=0;
    int m=0;
    printf("Enter the expression:\t");
    scanf("%s",infix);
    push('@');
    getnexttoken(infix);
    while ((ch=infix[l])!='\0')
    {
        if (ch==')')
        {
            push(ch);
        }
        else if (ch=='(')
        {
            while(stack[top]!=')')
            prefix[m++]=pop();
            element=pop();
        }
        else
        {
            if(precedence(stack[top])<=precedence(ch))
            {
                push(ch);
            }
            else
            {
                while(precedence(stack[top])>precedence(ch))
                prefix[m++]=pop();
                push(ch);
            }
        }
        l++;
    }
    while(stack[top]!='@')
    prefix[m++]=pop();
    prefix[m]='\0';
    getnexttoken(prefix);
    getnexttoken(infix);
    printf("Given infix expression:\t%s\nConverted Prefix expression:\t%s\n",infix,prefix);
}


void getnexttoken(char *w)
{
    int i=0;
    while(w[i]!='\0')
    {
        push(w[i]);
        i++;
    }
    int j=0;
    while(w[j]!='\0')
    {
        w[j]=pop();
        j++;
    }
}

int main()
{
   infixtoprefix();
   return 0; 
}