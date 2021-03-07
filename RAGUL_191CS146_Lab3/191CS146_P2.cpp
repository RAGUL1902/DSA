//The Program is Done using c++, So please use g++ to compile

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

struct Node* head = NULL;

//Inserting at the begining function
void InsertAtBegining(struct Node** head_temp, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_temp); 
    (*head_temp)    = new_node; 
} 

//Function to search the key
Node* Search(struct Node* head, int key) 
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

//Function to insert after LOC
void InsertAfterLOC(Node* prev_node, char new_data)   
{  
    if (prev_node == NULL)   
    {   
        cout << "the given previous node cannot be NULL";   
        return;   
    }  
    Node* new_node = new Node();  
    new_node->data = new_data;    
    new_node->next = prev_node->next;    
    prev_node->next = new_node;   
}

//Function to insert given value after given key
void Insert(char c; char d)
{
    if(NULL == Search(head,d))
        InsertAtBegining(&head,c);
    
    else
        InsertAfterLOC(Search(head,d),c);
}


int main()
{
    //head pointer
    struct Node* head = NULL;

    //Populating the linkedlist
    for(int i =0; i<10;i++)
    {
        InsertAtBegining(&head,'a' + i);
    }
    //Printing the values
    cout<<"Current linked list: \n";
    PrintList(head);

    //Searching operation
    cout<<"\nEnter the value to be searched: ";
    char b;
    cin>>b;
    if(NULL == Search(head,b))
    cout<<"The Element doesnot exist";
    else
    cout<<"LOC of the element is "<<Search(head,b);

    //Inserting after LOC operation
    cout<<"\nEnter the element to insert after LOC : ";
    char a;
    cin>>a;
    InsertAfterLOC(Search(head,b),a);
    cout<<"Current linked list: \n";
    PrintList(head);

    //Inserting given value after the given key
    cout<<"\nEnter the char to insert and the key after which to be inserted(with space): ";
    char c,d;
    cin>>c>>d;
    Insert(c,d);
    cout<<"Current linked list: \n";
    PrintList(head);
}
