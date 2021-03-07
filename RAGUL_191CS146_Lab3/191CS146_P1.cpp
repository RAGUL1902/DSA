//The Program is done using c++, so please use g++ to compile

// Importing headers
#include <iostream>
#include <string>
using namespace std;

//Structure definition
struct Node 
{ 
  char data; 
  struct Node *next; 
};


//Inserting at the begining function
void InsertAtBegining(struct Node** head_temp, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_temp); 
    (*head_temp)    = new_node; 
} 

//Function to search the key
Node* Search(struct Node* head, char key) 
{ 
    struct Node* LOC = head;   
    while (LOC != NULL) 
    { 
        if (LOC->data == key) 
            return LOC; 
        LOC = LOC->next; 
    } 
    return NULL; 
}

//Funtction to print the linked list
void PrintList(Node *node)  
{  
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
    }  
}

int main()
{
    struct Node* head = NULL;
    for(int i =0; i<10;i++)
    {
        InsertAtBegining(&head,'a' + i);
    }
    cout<<"Current linked list: \n";
    PrintList(head);
    cout<<"\nEnter the value to be inserted at the begining: ";
    char a;
    cin>>a;
    InsertAtBegining(&head,a);
    cout<<"\nLinked list after inserting "<<a<<" to the begining: "<<endl;
    PrintList(head);
    cout<<"\nEnter the value to be searched: ";
    char b;
    cin>>b;
    if(NULL == Search(head,b))
    cout<<"The Element doesnot exist";
    else
    cout<<"LOC of the element is "<<Search(head,b);
    
}
