#include<iostream>


using namespace std;
// A structure to make a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 


// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty");
        return 0;
    }

    return stack->array[stack->top--];
}
 
 

int main()
{
    struct Stack* stack = createStack(100);
    while(1){
        printf("\n\nEnter 1 to push an element: ");
        printf("\nEnter 2 to pop the top element: ");
        printf("\nEnter 3 to display all the elements by popping one by one");
        printf("\nEnter 4 to quit");
        printf("\n--> ");
        int choice;
        cin>>choice;
        if(choice == 4)
        return 0;
        if(choice == 1){
            int element;
            cout<<"\nEnter the element to push: ";
            cin>>element;
            push(stack,element);
            cout<<"\nElement is pushed into stack";
        }
        if(choice == 2){
            int element = pop(stack); 
            if(element != 0)
            cout<<"\nElement "<<element<<" is popped";
        }
        if(choice == 3){
            while(!isEmpty(stack)){
                int element = pop(stack);
                cout<<"\nElement "<<element<<" is popped";
            }
            if(isEmpty(stack)){
                cout<<"\nNow the stack is empty";
            }
        }

    }
    
 
    
    return 0;
}