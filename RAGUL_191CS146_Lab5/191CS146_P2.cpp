#include<iostream> 
#include <string.h>

using namespace std;
 
  
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  

struct Stack* createStack( unsigned size ) 
{ 
    struct Stack* stack = (struct Stack*)  
           malloc(sizeof(struct Stack)); 
  
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = size; 
  
    stack->array = (int*) malloc(stack->capacity *  
                                   sizeof(int)); 
  
    return stack; 
}



int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
}



char top(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
}



char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 



void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  

int isOperand(char ch) 
{ 
    return (ch >= '0' && ch <= '9'); 
} 
  
 
int Precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
  
  
  
int infixToPostfix(char* string) 
{ 
    int i, k; 
  
      
    struct Stack* stack = createStack(strlen(string)); 
    if(!stack)   
        return -1 ; 
  
    for (i = 0, k = -1; string[i]; ++i) 
    { 
          
         
        if (isOperand(string[i])){
            string[++k] = string[i];
        } 
             
          
         
        else if (string[i] == '('){
            push(stack, string[i]);
        } 
             
          
         
        else if (string[i] == ')') 
        { 
            while (!isEmpty(stack) && top(stack) != '('){
                string[++k] = pop(stack);
            }  
            if (!isEmpty(stack) && top(stack) != '(') 
                return -1;              
            else
                pop(stack); 
        } 
        else  
        { 
            while (!isEmpty(stack) &&  
                 Precedence(string[i]) <= Precedence(top(stack))) 
                {
                    string[++k] = pop(stack);
                } 
            push(stack, string[i]); 
        } 
  
    } 
  
     
    while (!isEmpty(stack)) 
        {
            string[++k] = pop(stack );
        } 
  
    string[++k] = '\0'; 
    printf( "%s", string ); 

    return 0;
} 
  
 
int main() 
{ 
    char string[100];
    cout<<"Enter your expression: ";
    cin>>string ;
    infixToPostfix(string); 
    return 0; 
} 